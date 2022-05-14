//https://www.acmicpc.net/problem/15686
//치킨배달 문제
// 조합알고리즘을 통해 구현
// 치킨집에서 M개를 고르고 각각의 M을 flood fill하여 구하면 됨. 
#include <iostream>
#include <queue>
#include <vector>

int N, M;
std::vector< std::vector<int> > map;
std::vector< std::pair<int, int> > chicken_house;
std::vector< std::pair<int, int> >house;
std::vector< std::vector<bool> > visited;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int calculate() {
	int rst = 10000000;
	std::vector<int> for_combination(chicken_house.size(),0);
	//조합을 위해서
	for (int i = 0; i < M; i++) {
		*(for_combination.end() - 1 - i) = 1;
	}

	do {
		std::vector< std::vector<int> > flood_fill(N, std::vector<int>(N, 1000000));
		for (int i = 0; i < chicken_house.size(); i++) {
			if (for_combination[i] != 1) continue;
			visited.assign(N, std::vector<bool>(N, false));
			std::queue< std::pair<int, int> > q;
			q.push(chicken_house[i]);
			visited[chicken_house[i].first][chicken_house[i].second] = true;


			while (!q.empty()) {
				auto front = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = front.first + dx[k];
					int ny = front.second + dy[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (!visited[nx][ny]) {
							if (flood_fill[nx][ny] > abs(nx - chicken_house[i].first) + abs(ny - chicken_house[i].second)) {
								flood_fill[nx][ny] = abs(nx - chicken_house[i].first) + abs(ny - chicken_house[i].second);
							}
							q.push(std::make_pair(nx, ny));
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
		
		int tmp = 0;
		for (auto i : house) {
			tmp += flood_fill[i.first][i.second];
		}
		rst = tmp < rst ? tmp : rst;
	} while (std::next_permutation(for_combination.begin(), for_combination.end()));

	return rst;
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) chicken_house.push_back(std::make_pair(i, j));
			if (map[i][j] == 1) house.push_back(std::make_pair(i, j));
		}
	}
	printf("%d", calculate());
}

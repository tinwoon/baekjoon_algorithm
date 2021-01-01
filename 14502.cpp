#include <iostream>
#include <queue>
#include <vector>

// dfs를 통해 해결
// 먼저 임의로 놓을 벽의 개수 세가지를 수열로 선택하고
// 바이러스가 해당 맵으로 번져간 후 안전한 구역을 확인한다.
 
int N, M;
std::vector< std::vector<int> > map;
std::queue< std::pair<int, int> > virus_location;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int calculate() {
	int rst = 0;
	std::vector<int> data(N * M - 3, 0);
	data.push_back(1);
	data.push_back(1);
	data.push_back(1);

	do {
		//맵을 복사해서 임의로 새운 벽에 1을 넣자
		auto map_cpy = map;
		auto virus_location_cpy = virus_location;
		bool flag = false;
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == 1) {
				if (map_cpy[i / M][i % M] != 0) {
					flag = true;
					break;
				}
				map_cpy[i / M][i % M] = 1;
			}
		}
		if (flag) continue;

		while (!virus_location_cpy.empty()) {
			std::vector< std::vector<bool> > visited(N, std::vector<bool>(M, false));
			int x = virus_location_cpy.front().first;
			int y = virus_location_cpy.front().second;
			virus_location_cpy.pop();

			std::queue< std::pair<int,int> > q;
			q.push(std::make_pair(x, y));
			visited[x][y] = true;

			while (!q.empty()) {
				auto front = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = front.first + dx[k];
					int ny = front.second + dy[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (!visited[nx][ny] && !map_cpy[nx][ny]) {
							q.push(std::make_pair(nx, ny));
							visited[nx][ny] = true;
							map_cpy[nx][ny] = 2;
						}
					}

				}

			}

		}
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			tmp += std::count(map_cpy[i].begin(), map_cpy[i].end(), 0);
		}
		if (tmp > rst) rst = tmp;

	} while (std::next_permutation(data.begin(), data.end()));

	return rst;
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) virus_location.push(std::make_pair(i, j));
		}
	}
	printf("%d", calculate());
}

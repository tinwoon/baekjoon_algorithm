//https://www.acmicpc.net/problem/10026
//적록색약 문제로 어려운 점은 없었다. 

#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector< std::vector<char> > map;
std::vector< std::vector<char> > map_RG;
std::vector< std::vector<bool> > visited;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int calculate(std::vector< std::vector<char> >& value_map) {

	int district = 0;
	visited.assign(N, std::vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			int color = value_map[i][j];
			std::queue< std::pair<int, int> >q;
			visited[i][j] = true;
			q.emplace(std::make_pair(i, j));
			while (!q.empty()) {
				auto front = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = front.first + dx[k];
					int ny = front.second + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (!visited[nx][ny] && value_map[nx][ny]== color) {
							visited[nx][ny] = true;
							q.emplace(std::make_pair(nx, ny));
						}
					}
				}
			}
			district++;
		}
	}
	
	return district;
}

int main() {
	scanf("%d", &N);
	map.assign(N, std::vector<char>(N, 0));
	map_RG.assign(N, std::vector<char>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'G') map_RG[i][j] = 'R';
			else map_RG[i][j] = map[i][j];
		}
	}
	int map_district = calculate(map);
	int map_district_RG = calculate(map_RG);
	printf("%d %d", map_district, map_district_RG);

}

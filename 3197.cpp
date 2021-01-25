//이 알고리즘 반드시 기억할것 
// https://www.acmicpc.net/problem/3197
#include <iostream>
#include <queue>
#include <vector>

int R, C;
std::queue< std::pair<int, int> > water_location;
std::queue< std::pair<int, int> > swan_location;
std::vector< std::vector<char> > map;
std::vector< std::pair<int, int> > swan;
std::vector< std::vector<bool> > visited;
std::vector< std::vector<bool> > s_can_visited;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int rst = 0;

void calculate() {

	std::queue< std::pair<int, int> > cpy_water;
	while (!water_location.empty()) {
		auto water_front = water_location.front();
		water_location.pop();
		visited[water_front.first][water_front.second] = true;

		for (int k = 0; k < 4; k++) {
			int nx = water_front.first + dx[k];
			int ny = water_front.second + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!visited[nx][ny] && map[nx][ny] == 'X') {
					cpy_water.emplace(std::make_pair(nx, ny));
					map[nx][ny] = '.';
					visited[nx][ny] = true;
				}
			}
		}
	}
	water_location = cpy_water;
	rst++;

}

bool can_meet() {

	std::queue< std::pair<int, int> > n_swan_location;

	while (!swan_location.empty()) {
		auto front = swan_location.front();
		swan_location.pop();

		for (int k = 0; k < 4; k++) {
			int nx = front.first + dx[k];
			int ny = front.second + dy[k];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (s_can_visited[nx][ny]) continue;
				if (map[nx][ny] == '.') {
					swan_location.emplace(std::make_pair(nx, ny));
					s_can_visited[nx][ny] = true;
				}
				else { 
					n_swan_location.emplace(std::make_pair(nx, ny)); 
					s_can_visited[nx][ny] = true;
				}
			}
		}
	}

	if (s_can_visited[swan[1].first][swan[1].second]) return true;
	swan_location = n_swan_location;
	return false;
}

int main() {
	scanf("%d %d", &R, &C);
	map.assign(R, std::vector<char>(C, 0));
	visited.assign(R, std::vector<bool>(C, false));
	s_can_visited.assign(R, std::vector<bool>(C, false));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'L') {
				swan.emplace_back(std::make_pair(i, j));
				map[i][j] = '.';
				water_location.emplace(std::make_pair(i, j));
			}
			else if (map[i][j] == '.') { 
				water_location.emplace(std::make_pair(i, j)); 
			}
		}
	}

	swan_location.emplace(std::make_pair(swan[0].first, swan[0].second));
	s_can_visited[swan[0].first][swan[0].second] = true;

	while (!can_meet()) {
		calculate();
	}
	printf("%d", rst);
}

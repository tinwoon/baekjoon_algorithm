//https://www.acmicpc.net/problem/3187
//문제가 3184번이랑 같아용... 

#include <iostream>
#include <queue>
#include <vector>

int R, C;
std::vector< std::vector<char> > map;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
std::vector< std::pair<int, int> > wolf;
std::vector< std::pair<int, int> > ship;
std::vector< std::vector<bool> > visited;

std::pair<int,int> calculate() {
	int ship_final_num = ship.size();
	int wolf_final_num = wolf.size();

	while (!wolf.empty()) {
		if (visited[wolf.back().first][wolf.back().second]) {
			wolf.pop_back();
			continue;
		}
		std::queue< std::pair<int, int> > q;
		q.emplace(wolf.back());
		visited[wolf.back().first][wolf.back().second] = true;
		wolf.pop_back();
		int ship_num = 0;
		int wolf_num = 1;

		while (!q.empty()) {
			auto front = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = front.first + dx[k];
				int ny = front.second + dy[k];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
					if (!visited[nx][ny] && map[nx][ny] != '#') {
						if (map[nx][ny] == 'v') wolf_num++;
						else if (map[nx][ny] == 'k') ship_num++;
						visited[nx][ny] = true;
						q.emplace(std::make_pair(nx, ny));
					}
				}
			}
		}
		if (wolf_num < ship_num) wolf_final_num -= wolf_num;
		else ship_final_num -= ship_num;
	}
	
	return std::make_pair(ship_final_num, wolf_final_num);
}

int main() {
	scanf("%d %d", &R, &C);
	map.assign(R, std::vector<char>(C, 0));
	visited.assign(R, std::vector<bool>(C, false));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'v') wolf.emplace_back(std::make_pair(i, j));
			if (map[i][j] == 'k') ship.emplace_back(std::make_pair(i, j));
		}
	}

	auto rst = calculate();
	printf("%d %d", rst.first, rst.second);
}

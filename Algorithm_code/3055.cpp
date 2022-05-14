#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>


int R, C;
std::vector< std::vector<char> > map;
std::vector< std::vector<bool> > visited;
std::vector< std::tuple<int,int, int> > water;
std::pair<int, int> D;
std::pair<int, int> S;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };



void bfs() {

	std::queue< std::tuple<int,int,int> > q;
	q.push(std::make_tuple(S.first,S.second,0));
	visited[S.first][S.second] = true;

	while (!q.empty()) {
		auto front = q.front();
		int x, y, z;
		std::tie(y, x, z) = front;
		q.pop();

		if (y == D.first && x == D.second) {
			printf("%d", z);
			return;
		}


		//별위 위치를 받아야함

		for (int k = 0; k < 4; k++) {
			for (int l = 0; l < water.size(); l++) {
				if (z == std::get<2>(water[l])) {
					int nx = std::get<1>(water[l]) + dx[k];
					int ny = std::get<0>(water[l]) + dy[k];
					if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] == '.') {
						map[ny][nx] = '*';
						water.push_back(std::make_tuple(ny, nx,z+1));
					}
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
				if (!visited[ny][nx] && map[ny][nx] != '*' && map[ny][nx] != 'X') {
					q.push(std::make_tuple(ny,nx,z+1));
					visited[ny][nx] = true;
				}
			}
		}


	}
	printf("KAKTUS");

}



int main() {
	scanf("%d %d", &R, &C);
	map.assign(R, std::vector<char>(C,0));
	visited.assign(R, std::vector<bool>(C,0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//scanf("%1c", &map[i][j]);
			std::cin >> map[i][j];
			if (map[i][j] == 'D') {
				D.first = i;
				D.second = j;
			}else if (map[i][j] == 'S') {
				S.first = i;
				S.second = j;
			}else if (map[i][j] == '*') {
				water.push_back(std::make_tuple(i,j,0));
			}

		}
	}
	bfs();
}

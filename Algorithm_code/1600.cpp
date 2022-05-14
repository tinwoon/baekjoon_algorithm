//1600 말이 되고픈 원숭이 문제도 벽부수기 2(14442)와 마찬가지로 3중 visited로 구성해야 함
 

#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

int K, W, H;
std::vector< std::vector<int> > map;
std::vector< std::vector< std::vector<bool> > >visited;

int dx[12] = { -1,0,1,0, 1,2,2,1,-1,-2,-2,-1 };
int dy[12] = { 0,1,0,-1, -2,-1,1,2,-2,-1,1,2 }; 



int calculate() {
	std::queue< std::tuple<int, int, int, int> > q;
	q.emplace(std::make_tuple(0, 0, 0,0));
	visited[0][0][0] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int x, y, z, num;
		std::tie(x, y, z, num) = front;

		if (x == H - 1 && y == W - 1) return num;

		for (int k = 0; k < 12; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (k < 4 && !visited[nx][ny][z] && map[nx][ny] != 1) {
					q.emplace(std::make_tuple(nx, ny, z, num + 1));
					visited[nx][ny][z] = true;
				}
				else if (!visited[nx][ny][z+1] && map[nx][ny] != 1 && z < K) {
					q.emplace(std::make_tuple(nx, ny, z + 1, num + 1));
					visited[nx][ny][z + 1] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d", &K);
	scanf("%d %d", &W, &H);
	map.assign(H, std::vector<int>(W, 0));
	visited.assign(H, std::vector< std::vector<bool> >(W, std::vector<bool>(30,false)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", calculate());
}

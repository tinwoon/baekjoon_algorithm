#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>



//벽뿌수기 알고리즘은 한번 외워야할 듯

int N, M;
std::vector< std::vector<int> > map;
int value[1000][1000][2];
bool visited[1000][1000][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


void bfs(int i, int j) {
	std::queue< std::tuple<int,int,int> > q;
	q.push(std::tuple <int,int,int>(i,j,0));
	value[i][j][0] = 1;
	visited[i][j][0] = true;

	while (!q.empty()) {
		
		auto front = q.front();
		q.pop();
		int x, y, z;
		std::tie(y, x, z) = front;

		for (int k = 0; k < 4; k++) {

			int ny = y + dy[k];
			int nx = x + dx[k];
			
			if (nx >= 0 && nx < M && ny >=0 && ny < N) {
				if (!visited[ny][nx][z] && map[ny][nx] == 0) {
					q.push(std::tuple<int, int, int>(ny, nx, z));
					visited[ny][nx][z] = true;
					value[ny][nx][z] = value[y][x][z] + 1;
				}
				if (!visited[ny][nx][1] && z == 0 && map[ny][nx] == 1) {
					q.push(std::tuple<int, int, int>(ny, nx, z+1));
					visited[ny][nx][z + 1] = true;
					value[ny][nx][z + 1] = value[y][x][z] + 1;
				}
			}

		}


	}

}


int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M, 0));



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	bfs(0, 0);
	int rst = std::min(value[N - 1][M - 1][0] > 0 ? value[N - 1][M - 1][0]:2000000000, value[N - 1][M - 1][1] > 0 ? value[N - 1][M - 1][1] : 2000000000);

	printf("%d", rst!=2000000000?rst:-1);
}

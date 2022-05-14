#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


//가중치 bfs로 같은 방식을 사용함
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int N, M;
std::vector< std::vector<int> > map;
std::vector< std::vector<bool> > visited;
std::vector< std::vector<int> > value;

void bfs(int i, int j) {

	std::queue< std::pair<int, int> > q;
	std::queue< std::pair<int, int> > next_q;
	q.push(std::pair<int,int>(i,j));
	visited[i][j] = true;


	while (!q.empty()) {
		std::pair<int,int> front = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = front.first + dy[k];
			int nx = front.second + dx[k];
			
			if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
				if (!visited[ny][nx]) {

					if (!map[ny][nx]) {
						q.push(std::pair<int, int>(ny, nx));
						visited[ny][nx] = true;
						value[ny][nx] = value[front.first][front.second];
					}
					if (map[ny][nx]) {
						next_q.push(std::pair<int, int>(ny, nx));
						visited[ny][nx] = true;
						value[ny][nx] = value[front.first][front.second] + 1;
					}
				}
			}
		}

		if (q.empty()) {
			q = next_q;
			next_q = std::queue< std::pair<int, int> >();
		}

	}
	



}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(M, std::vector<int>(N, 0));
	value.assign(M, std::vector<int>(N, 0));
	visited.assign(M, std::vector<bool>(N, false));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
	printf("%d",value[M-1][N-1]);
}

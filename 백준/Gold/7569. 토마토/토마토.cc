#pragma warning (disable : 4996)
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

int M, N, H;
std::vector< std::vector< std::vector<int> > > tomato;
std::vector< std::vector< std::vector<bool> > > visited;
std::priority_queue< std::tuple<int, int, int, int> > pq;
int tomato_count, pull_tomato;

int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int calculate() {

	while (!pq.empty()) {
		int h, m, n, time;
		std::tie(time, n, m, h) = pq.top();
		time *= -1;
		pq.pop();

		for (int k = 0; k < 6; k++) {
			int nx = n + dx[k];
			int ny = m + dy[k];
			int nz = h + dz[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H) {
				if (!visited[nx][ny][nz] && tomato[nx][ny][nz] != -1) {
					visited[nx][ny][nz] = true;
					pq.emplace(std::make_tuple((-1*time - 1), nx, ny, nz));
					pull_tomato++;
					if (pull_tomato == tomato_count) return time + 1;
				}
			}
		}
	}

	return tomato_count == pull_tomato ? 0 : -1;
}


int main() {
	scanf("%d %d %d", &M, &N, &H);
	tomato.assign(N, std::vector< std::vector<int> >(M, std::vector<int>(H, 0)));
	visited.assign(N, std::vector< std::vector<bool> >(M, std::vector<bool>(H, false)));
	
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				scanf("%d", &tomato[n][m][h]);
				//익은 토마토
				if (tomato[n][m][h] == 1) {
					pq.emplace(0, n, m, h);
					visited[n][m][h] = true;
					pull_tomato++;
					tomato_count++;
				}
				//익지 않은 토마토
				else if (tomato[n][m][h] == 0) {
					tomato_count++;
				}
			}
		}
	}
	
	printf("%d\n", calculate());
}
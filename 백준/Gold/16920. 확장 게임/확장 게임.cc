#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int N, M, P;
std::vector<int> S;
std::vector< std::vector<char> > map;
std::vector< std::vector<bool> > visited;
std::vector< std::queue< std::pair<int, int> > > q;
std::vector<int> ans;
bool q_n_empty_flag;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


void calculate() {

	while (q_n_empty_flag) {
		q_n_empty_flag = false;
		for (int p = 1; p <= P; p++) {

			for (int s = 0; s < S[p]; s++) {
				std::queue< std::pair<int, int> > nq;
				while (!q[p].empty()) {
					auto front = q[p].front();
					int x = front.first;
					int y = front.second;
					q[p].pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
							if (!visited[nx][ny] && map[nx][ny] == '.') {
								visited[nx][ny] = true;
								nq.emplace(std::make_pair(nx, ny));
								map[nx][ny] = p;
								ans[p]++;
								//P개의 q들 중 q가 비어있지 않는게 있다.
								q_n_empty_flag = true;
							}
						}
					}
				}
				q[p] = nq;
				if (q[p].empty()) break;
			}

		}
	}


	for (int player = 1; player <= P; player++) {
		printf("%d ", ans[player]);
	}
	return;
}

int main() {
	scanf("%d %d %d", &N, &M, &P);
	S.assign(P + 1, 0);
	map.assign(N, std::vector<char>(M, '.'));
	q.assign(P + 1, std::queue< std::pair<int, int> >());
	ans.assign(P + 1, 0);
	visited.assign(N, std::vector<bool>(M, false));

	for (int p = 1; p <= P; p++) {
		scanf("%d", &S[p]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if ('1' <= map[i][j] && map[i][j] <= '9') {
				int player = map[i][j] - '0';
				q[player].emplace(std::make_pair(i, j));
				visited[i][j] = true;
				ans[player]++;
				q_n_empty_flag = true;
			}
		}
	}

	calculate();
}
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

int N, M, K;
std::queue< std::tuple<int, int, int, int, int> > q;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
//i,j 좌표에 m,s,c에 해당하는 파이어 볼이 있다.
std::vector< std::tuple<int,int,int> > visited[55][55];
int ans = 0;

void calculate(int num) {
	if (num == K) {
		while (!q.empty()) {
			int r, c, m, s, d;
			std::tie(r, c, m, s, d) = q.front();
			q.pop();
			ans += m;
		}
		return;
	}
	
	while (!q.empty()) {
		int r, c, m, s, d;
		std::tie(r,c,m,s,d) = q.front();
		q.pop();
		visited[r][c].erase(visited[r][c].begin(), visited[r][c].begin() + 1);
		int nx = r + s * dx[d];
		int ny = c + s * dy[d];
		if (nx < 1) nx = (nx-1 + 300 * N) % N + 1;
		if (ny < 1) ny = (ny-1 + 300 * N) % N + 1;
		if (nx > N) nx = (nx-1) % N + 1;
		if (ny > N) ny = (ny-1) % N + 1;
		if (m != 0) visited[nx][ny].emplace_back(std::make_tuple(m, s, d));
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j].size() == 1) {
				int m, s, d;
				std::tie(m, s, d) = visited[i][j][0];
				q.emplace(std::make_tuple(i, j, m, s, d));
			}
			if (visited[i][j].size() > 1) {
				int m_s = 0, s_s = 0, d_s = 0;
				int size = visited[i][j].size();
				for (int k = 0; k < size; k++) {
					int m, s, d;
					std::tie(m, s, d) = visited[i][j][k];
					m_s += m;
					s_s += s;
					if (d % 2 == 0) d_s++;
				}
				int is_all_same = 1;
				if (d_s == size || d_s == 0) is_all_same = 0;

				visited[i][j].clear();

				if (m_s/5 != 0) {
					visited[i][j].emplace_back(std::make_tuple(m_s / 5, s_s / size, 0 + is_all_same));
					q.emplace(std::make_tuple(i, j, m_s / 5, s_s / size, 0 + is_all_same));
					visited[i][j].emplace_back(std::make_tuple(m_s / 5, s_s / size, 2 + is_all_same));
					q.emplace(std::make_tuple(i, j, m_s / 5, s_s / size, 2 + is_all_same));
					visited[i][j].emplace_back(std::make_tuple(m_s / 5, s_s / size, 4 + is_all_same));
					q.emplace(std::make_tuple(i, j, m_s / 5, s_s / size, 4 + is_all_same));
					visited[i][j].emplace_back(std::make_tuple(m_s / 5, s_s / size, 6 + is_all_same));
					q.emplace(std::make_tuple(i, j, m_s / 5, s_s / size, 6 + is_all_same));
				}
				
			}
		}
	}
	calculate(num + 1);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int k = 0; k < M; k++) {
		int r, c, m, s, d;
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		q.emplace(std::make_tuple(r, c, m, s, d));
		visited[r][c].emplace_back(std::make_tuple(m, s, d));
	}
	calculate(0);
	printf("%d", ans);
}

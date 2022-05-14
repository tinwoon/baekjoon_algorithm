//14442 ���μ��� �̵��ϱ� 2
// K���� ������ ���� �μż� ���� �� �� �ִٸ� ���� ���� ������� �����ص� �ȴ�
// �� �������� ���ؼ��� VISITED�� x,y���� �ƴ� ���� �� �� �ν�ä�� �湮�ߴ��� ���� �����ϴ� 3�� visited�� �����ؾ���
// visited[x][y][num]������ �����ؾ� ������ ����.
// �� �˰��� ����ϱ�. 

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int N, M, K;
std::vector< std::vector<int> > map;
std::vector< std::vector< std::vector<bool> > > visited;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int calculate() {
	std::queue< std::tuple<int, int, int, int> >q;
	q.emplace(std::make_tuple(0, 0, 0, 1));
	visited[0][0][0] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int x, y, z, num;
		std::tie(x, y, z, num) = front;

		if (x == N - 1 && y == M - 1) return  num;

		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visited[nx][ny][z] && map[nx][ny] == 0) {
					q.emplace(std::make_tuple(nx, ny, z, num + 1));
					visited[nx][ny][z]= true;
				}
				if (z < K) {
					if (!visited[nx][ny][z + 1] && map[nx][ny] == 1) {
						q.emplace(std::make_tuple(nx, ny, z + 1, num + 1));
						visited[nx][ny][z + 1] = true;
					}
				}
				
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	map.assign(N, std::vector<int>(M, 0));
	visited.assign(N, std::vector< std::vector<bool> >(M, std::vector<bool>(11,false)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d", calculate());
}

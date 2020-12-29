#include <iostream>
#include <vector>

//ù��°�� ������ ����
// change_dir�� �߸���
// �ι�°�� ������ ����
// û�ұⰡ �ڷ� ������ �ڷ� �� ������ �ι� �ڷ� ���Ⱦ�� �ߴµ� ���� ������ ��.

int N, M;
std::vector< std::vector<int> > map;
std::vector< std::vector<bool> > is_clean;
int r, c, dir;
int rst = 0;
int change_dir[4] = { 0,3,2,1 };
int dx[4] = { 0, 1,0,-1 };
int dy[4] = { -1,0,1,0 };

int calculate() {

	dir = change_dir[dir];

	while (1) {

		is_clean[r][c] = true;
		bool escape = false;
		rst++;

		for (int i = 0; i < 4; i++) {
			int nx = r + dx[(i + dir) % 4];
			int ny = c + dy[(i + dir) % 4];
			if (!is_clean[nx][ny] && !map[nx][ny]) {
				r = nx;
				c = ny;
				dir = (i + dir + 1) % 4;
				escape = true;
				break;
			}
		}
		if (escape) continue;

		r += dx[(1 + dir) % 4];
		c += dy[(1 + dir) % 4];
		rst--;
		if (map[r][c]) {
			rst++;
			return rst;
		}

	}

}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &dir);
	
	map.assign(N, std::vector<int>(M, 0));
	is_clean.assign(N, std::vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	printf("%d", calculate());

	
}

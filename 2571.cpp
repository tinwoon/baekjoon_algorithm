#include <iostream>
#include <algorithm>
#include <vector>

//������ 3����
//�ش� ������ �ٸ��� Ǫ�� ����� �ִ�.
//����� �׳� �ܼ��� ����������, x, y�� �������� �������� �󸶸�ŭ�� ���ӵǴ��� �����ϸ� �ȴ�.
//���� ��� 1,1��ǥ���� �����ʱ��� 10��ŭ�� 1�̸� dp[1][1] = 10�̴�.
//�̷� ������� 2,1 ��ǥ������ dp[2][1]�� ������ Ȯ���ϰ� ���̸� ����ؼ� �����ϸ鼭 Ȯ���Ѵ�.

int N;
bool map[101][101];
int min_x = 100, min_y = 100, max_x = 1, max_y = 1;
int ans = -1;

bool is_true(int x, int y, int i, int j) {
	if (x == 11 && y == 11 && i == 1 && j == 12) {
		printf("");
	}
	for (int s_x = i; s_x < i + x; s_x++) {
		for (int s_y = j; s_y < j + y; s_y++) {
			if (!map[s_x][s_y]) return false;
		}
	}
	return true;
}

int calculate() {
	for (int x = max_x - min_x + 10; x >= 1; x--) {
		for (int y = max_y - min_y + 10; y >= 1; y--) {
			if (x * y <= ans) continue;
			for (int i = min_x; i <= max_x + 10; i++) {
				for (int j = min_y; j <= max_y + 10; j++) {
					if (is_true(x, y, i, j)) {
						ans = std::max(x * y, ans);
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int x, y;
		scanf("%d %d", &x, &y);
		min_x = std::min(min_x, x);
		min_y = std::min(min_y, y);
		max_x = std::max(max_x, x);
		max_y = std::max(max_y, y);
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				map[i][j] = true;
			}
		}
	}
	printf("%d", calculate());
}
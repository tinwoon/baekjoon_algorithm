#include <vector>
#include <algorithm>

int N, M;
bool icecream[201][201];

int calculate() {
	int rst = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (icecream[i][j] || icecream[i][k] || icecream[j][k]) continue;
				rst++;
			}
		}
	}
	return rst;
}



int main() {
	scanf("%d %d", &N, &M);

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		icecream[a][b] = icecream[b][a] = true;
	}
	printf("%d", calculate());
}

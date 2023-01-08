#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int N, M, w, x, y, a, b;
std::vector< std::vector<int> > tree;
std::vector< std::vector<int> > data;

void update(int i, int j, int num) {
	int j_s = j;
	while (i <= N) {
		while (j <= N) {
			tree[i][j] += num;
			j += (j & -j);
		}
		j = j_s;
		i += (i & -i);
	}
}

int sum(int i, int j) {
	int ans = 0, j_s = j;
	while (i > 0) {
		while (j > 0) {
			ans += tree[i][j];
			j -= (j & -j);
		}
		j = j_s;
		i -= (i & -i);
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &M);
	tree.assign(N + 1, std::vector<int>(N + 1, 0));
	data.assign(N + 1, std::vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &data[i][j]);
			update(i, j, data[i][j]);
		}
	}

	for (int k = 0; k < M; k++) {
		scanf("%d", &w);
		if (w) {
			scanf("%d %d %d %d", &x, &y, &a, &b);
			printf("%d\n", sum(a, b) - sum(x - 1, b) - sum(a, y - 1) + sum(x - 1, y - 1));
		}
		else {
			scanf("%d %d %d", &x, &y, &a);
			update(x, y, a - data[x][y]);
			data[x][y] = a;
		}
	}
	
}
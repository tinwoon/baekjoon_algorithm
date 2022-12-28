#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

int N, M;
std::vector<int> tree;
std::vector<int> data;

int init(int start, int end, int index) {
	if (start == end) return tree[index] = data[start];

	int mid = (start + end) / 2;
	return tree[index] = std::min(init(start, mid, index * 2), init(mid + 1, end, index * 2 + 1));
}

//최소 값을 구하기 위함.
int calculate(int left, int right, int start, int end, int index) {
	if (left <= start && end <= right) return tree[index];

	if (end < left || right < start) return INT_MAX;

	int mid = (start + end) / 2;
	return std::min(calculate(left, right, start, mid, index * 2), calculate(left, right, mid + 1, end, index * 2 + 1));
}

int update(int start, int end, int index, int idx, int value) {

	if (start > idx || idx > end) return tree[index];
	if (start == end) return tree[index] = value;

	int mid = (start + end) / 2;
	return tree[index] = std::min(update(start, mid, index * 2, idx, value), update(mid + 1, end, index * 2 + 1, idx, value));
	
}


int main() {
	scanf("%d", &N);
	data.assign(N, 0);
	int lg = ceil(log2(N)) + 1;
	tree.assign(1 << lg, INT_MAX);

	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}

	init(0, N - 1, 1);

	scanf("%d", &M);
	for (int k = 0; k < M; k++) {
		int cmd, l, r;
		scanf("%d %d %d", &cmd, &l, &r);
		switch (cmd) {
			case 1:
				data[l-1] = r;
				update(0, N - 1, 1, l-1, r);
				break;
			case 2:
				printf("%d\n", calculate(l - 1, r - 1, 0, N - 1, 1));
				break;
		}
	}
}
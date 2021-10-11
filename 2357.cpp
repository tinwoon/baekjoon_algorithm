#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

//세그먼트 트리이다.

int N, M;
std::vector<int> data;
//최소값, 최대 값
std::vector < std::pair<int, int> > tree;


std::pair<int, int> make_tree(int node, int start, int end) {
	if (start == end) return tree[node] = std::make_pair(data[start], data[start]);
	int mid = (start + end) / 2;

	std::pair<int, int> left = make_tree(node * 2, start, mid);
	std::pair<int, int> right = make_tree(node * 2 + 1, mid + 1, end);

	return tree[node] = std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
}

std::pair<int, int> calculate(int node, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return std::make_pair(INT_MAX, INT_MIN);
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	std::pair<int, int> left_n = calculate(node * 2, start, mid, left, right);
	std::pair<int, int> right_n = calculate(node * 2 + 1, mid + 1, end, left, right);
	return std::make_pair(std::min(left_n.first, right_n.first), std::max(left_n.second, right_n.second));
}

int main() {
	scanf("%d %d", &N, &M);
	data.assign(N, 0);
	int size = ceil(log2(N)) + 1;
	tree.assign(1 << size, std::pair<int, int>());

	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}
	make_tree(1, 0, N - 1);
	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		auto ans = calculate(1, 0, N - 1, a - 1, b - 1);
		printf("%d %d\n", ans.first, ans.second);
	}
}
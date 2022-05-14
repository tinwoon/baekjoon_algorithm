#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

//1725 히스토그램 구하기 문제
//전형적인 세그먼트 트리 문제이지만 응용력의 이해가 필요했다.
//일단 기본적으로 유니온 파인드에서 get_parent, union_n, find는 작성하고 시작하듯
//세그먼트 트리역시 make_tree와 calculate함수는 작성해야할 듯 하다.

std::vector<int> data;
std::vector<int> tree;
int ans = 0;
int N;

//tree의 node에는 해당 범위 중 가장 작은 인덱스 값을 가지고 있다.
int make_tree(int node, int start, int end) {
	if (start == end) return tree[node] = end;
	int mid = (start + end) / 2;
	int left_val = make_tree(node * 2, start, mid);
	int right_val = make_tree(node * 2 + 1, mid + 1, end);
	return tree[node] = data[left_val] < data[right_val] ? left_val : right_val;
}

//해당 범위에 속하는 애들 중 가장 작은 node
int calculate(int node, int start, int end, int left, int right) {
	if (start >= left && end <= right) return tree[node];
	if (start > right || end < left) return INT_MAX;

	int mid = (start + end) / 2;
	int left_val = calculate(node * 2, start, mid, left, right);
	int right_val = calculate(node * 2 + 1, mid + 1, end, left, right);
	if (left_val == INT_MAX) return right_val;
	else if (right_val == INT_MAX) return left_val;
	return data[left_val] < data[right_val] ? left_val : right_val;
}

void solve(int left, int right) {
	if (left > right) return;

	int index = calculate(1, 0, N - 1, left, right); // 구간 내의 최소값 찾기

	ans = std::max(ans, data[index] * (right - left + 1));

	solve(left, index - 1);
	solve(index + 1, right);

}

int main() {
	scanf("%d", &N);
	int tree_size = ceil(log2(N));
	data.assign(N, 0);
	tree.assign(1 << (tree_size + 1), 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}
	make_tree(1, 0, N - 1);
	solve(0, N - 1);
	printf("%d", ans);
}
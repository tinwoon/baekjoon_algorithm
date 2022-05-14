#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

//1725 ������׷� ���ϱ� ����
//�������� ���׸�Ʈ Ʈ�� ���������� ������� ���ذ� �ʿ��ߴ�.
//�ϴ� �⺻������ ���Ͽ� ���ε忡�� get_parent, union_n, find�� �ۼ��ϰ� �����ϵ�
//���׸�Ʈ Ʈ������ make_tree�� calculate�Լ��� �ۼ��ؾ��� �� �ϴ�.

std::vector<int> data;
std::vector<int> tree;
int ans = 0;
int N;

//tree�� node���� �ش� ���� �� ���� ���� �ε��� ���� ������ �ִ�.
int make_tree(int node, int start, int end) {
	if (start == end) return tree[node] = end;
	int mid = (start + end) / 2;
	int left_val = make_tree(node * 2, start, mid);
	int right_val = make_tree(node * 2 + 1, mid + 1, end);
	return tree[node] = data[left_val] < data[right_val] ? left_val : right_val;
}

//�ش� ������ ���ϴ� �ֵ� �� ���� ���� node
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

	int index = calculate(1, 0, N - 1, left, right); // ���� ���� �ּҰ� ã��

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
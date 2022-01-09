#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

//6549 ������׷����� ���� ū ���簢�� ����
//���׸�Ʈ Ʈ���� ���� ������ �ذ�
//���� ���� ��带 �������� ����, ������ ���� ū ������׷� �ľ�

int N;
std::vector<long long> height;
std::vector< std::pair<long long, int> > tree;
long long ans;

//tree �ʱ�ȭ
std::pair<long long, int> make_tree(int node, int start, int end) {
	if (start == end) {
		return tree[node] = std::make_pair(height[start], start);
	}
	int mid = (start + end) / 2;
	return tree[node] = std::min(make_tree(node * 2, start, mid), make_tree(node * 2 + 1, mid + 1, end));
}

//left, right ���̿� �ִ� height �� ���� ���� ����, index
std::pair<long long, int> find_value(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return std::make_pair(LLONG_MAX, -1);
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return std::min(find_value(node * 2, start, mid, left, right), find_value(node * 2 + 1, mid + 1, end, left, right));
}

//�ϳ��� ���ϴ� ���� �ʿ�
void calculate(int left, int right) {
	auto ret = find_value(1, 0, N - 1, left, right);

	if (ret.first == LLONG_MAX) return;

	ans = std::max(ans, (ret.first) * ((long long)right - (long long)left + 1));

	calculate(left, ret.second - 1);
	calculate(ret.second + 1, right);
}

int main() {

	while (1) {
		ans = 0;
		scanf("%d", &N);
		if (N == 0) break;
		height.assign(N, 0);
		int tree_size = (int)ceil(log2(N));
		tree.assign(1 << (tree_size + 1), std::make_pair(0, 0));
		for (int k = 0; k < N; k++) {
			scanf("%lld", &height[k]);
		}
		make_tree(1, 0, N - 1);
		calculate(0, N - 1);
		printf("%lld\n", ans);
	}

}
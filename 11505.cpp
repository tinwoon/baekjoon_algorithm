#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <math.h>

//11505 ���������ϱ�
//�������� ���׸�Ʈ Ʈ���̴�.
//�ش� Ǯ�� ����� �� ����صδ°� ����.

#define DIV 1000000007
int N, M, K;
std::vector<long long> data;
std::vector<long long> tree;

//node ��ȣ�� 1������ �����Ѵ�.
long long init(int node, int start, int end) {
	if (start == end) return tree[node] = data[start] % DIV;
	else return tree[node] = (init(node * 2, start, (start + end) / 2) * init(node * 2 + 1, ((start + end) / 2) + 1, end)) % DIV;
}

long long sum(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 1;
	if (left <= start && right >= end) return tree[node] % DIV;
	else {
		int mid = (start + end) / 2;
		return (sum(node * 2, start, mid, left, right) * sum(node * 2 + 1, mid + 1, end, left, right)) % DIV;
	}
}

//node�� tree��, start���� end������ �迭, �ٲٰ��� �ϴ� index�� �ٲ��ش�.
long long update(int node, int start, int end, int index, long long present) {
	if (index > end || index < start) return tree[node];
	if (start == end) {
		return tree[node] = present % DIV;
	}
	int mid = (start + end) / 2;
	return tree[node] = (update(node * 2, start, mid, index, present) * update(node * 2 + 1, mid + 1, end, index, present)) % DIV;
}



int main() {
	scanf("%d %d %d", &N, &M, &K);
	data.assign(N, 0);
	tree.assign(1 << ((int)ceil(log2(N)) + 1), 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &data[k]);
	}
	init(1, 0, N - 1);
	for (int k = 0; k < M + K; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			long long prev = data[b - 1];
			data[b - 1] = c % DIV;
			update(1, 0, N - 1, b - 1, c % DIV);
		}
		else printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1) % DIV);
	}
}
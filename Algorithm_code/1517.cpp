#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 1000001

//inversion counting 문제이지만
//B.emplace_back(std::make_pair(A[k], k)); 를 통해 정렬 후에 위치가 어디로 이동하는지 확인하는 기법을 기억해두자.


int N;
int size;
std::vector<int> A;
std::vector< std::pair<int, int> > B;
std::vector<long long> tree;

void update(int node, int start, int end, int index, int diff) {
	if (index < start || index > end) return;
	tree[node] += (long long)diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	else if (start >= left && end <= right) return tree[node];
	else {
		int mid = (start + end) / 2;
		return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
	}
}


long long calculate() {
	long long ans = 0;
	for (int k = 0; k < N; k++) {
		update(1, 0, N - 1, B[k].second, 1);
		ans += sum(1, 0, N - 1, (B[k].second) + 1, N - 1);
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	A.assign(N, 0);


	size = ceil(log2(N)) + 1;
	tree.assign(1 << size, 0);

	for (int k = 0; k < N; k++) {
		scanf("%d", &A[k]);
		B.emplace_back(std::make_pair(A[k], k));
	}
	std::sort(B.begin(), B.end());

	printf("%lld", calculate());
}
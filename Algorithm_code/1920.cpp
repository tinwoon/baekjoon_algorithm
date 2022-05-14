#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> A;

bool calculate(int value) {
	int begin = 0, end = N - 1;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (A[mid] < value) {
			begin = mid + 1;
		}
		else if (A[mid] > value) {
			end = mid - 1;
		}
		else return true;
	}
	return false;
}

int main() {
	scanf("%d", &N);
	A.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &A[k]);
	}
	std::sort(A.begin(), A.end());
	scanf("%d", &M);
	for (int k = 0; k < M; k++) {
		int value;
		scanf("%d", &value);
		printf("%d\n", calculate(value));
	}
}
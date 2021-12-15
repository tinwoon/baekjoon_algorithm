#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//2143 두 배열의 합
//이분 탐색과 부분합을 사용하는 문제로 보여진다.
//풀이 방법은 투포인터 방식 및 부분합 방식으로 풀이 예정

int T;
int A_size, B_size;
std::vector< std::vector<int> > prefix_A;
std::vector< std::vector<int> > prefix_B;
std::vector<int> sort_A;


void calculate() {
	for (int i = 0; i < A_size; i++) {
		for (int j = i; j < A_size; j++) {
			prefix_A[i][j] = (i == 0 ? (prefix_A[0][j]) : (prefix_A[0][j] - prefix_A[0][i - 1]));
			sort_A.emplace_back(prefix_A[i][j]);
		}
	}

	std::sort(sort_A.begin(), sort_A.end());
}

int main() {
	scanf("%d", &T);
	scanf("%d", &A_size);
	prefix_A.assign(A_size, std::vector<int>(A_size, 0));
	for (int k = 0; k < A_size; k++) {
		int a;
		scanf("%d", &a);
		prefix_A[0][k] = (k == 0 ? a : prefix_A[0][k - 1] + a);
	}
	scanf("%d", &B_size);
	prefix_B.assign(B_size, std::vector<int>(B_size, 0));
	for (int k = 0; k < B_size; k++) {
		int b;
		scanf("%d", &b);
		prefix_B[0][k] = (k == 0 ? b : prefix_B[0][k - 1] + b);
	}
}
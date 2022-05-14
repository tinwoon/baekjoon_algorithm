#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

//2143 두 배열의 합

int T;
int A_size, B_size;
//A 배열에 대한 부분합을 저장
std::vector<int> subtotal_A;
//B 배열에 대한 부분합을 저장
std::vector<int> subtotal_B;
std::map<int, int> A_data;
std::map<int, int> B_data;


long long calculate() {
	long long ans = 0;

	//A 부분합의 모든 종류를 MAP에 넣기 위해
	for (int i = 0; i < A_size; i++) {
		for (int j = i; j < A_size; j++) {
			//i부터 j까지의 부분합을 넣는다.(A[2] + A[3] + A[4]의 경우 i는 2, j는 4에 해당)
			int i_to_j = (i == 0 ? (subtotal_A[j]) : (subtotal_A[j] - subtotal_A[i - 1]));
			//i_to_j가 데이터에 없으면 넣고, 있으면 ++해서 개수를 추가해준다.
			if (A_data.insert(std::make_pair(i_to_j, 1)).second == false) {
				A_data[i_to_j]++;
			}
		}
	}

	//B 부분합의 모든 종류를 MAP에 넣기 위해
	for (int i = 0; i < B_size; i++) {
		for (int j = i; j < B_size; j++) {
			//i부터 j까지의 부분합을 넣는다.(B[2] + B[3] + B[4]의 경우 i는 2, j는 4에 해당)
			int i_to_j = (i == 0 ? (subtotal_B[j]) : (subtotal_B[j] - subtotal_B[i - 1]));
			//i_to_j가 데이터에 없으면 넣고, 있으면 ++해서 개수를 추가해준다.
			if (B_data.insert(std::make_pair(i_to_j, 1)).second == false) {
				B_data[i_to_j]++;
			}
		}
	}

	//T에 해당하는 값의 개수를 구하기 위해(A의 부분합이 k고 B의 부분합이 T - k이면 둘의 합은 T이다)
	for (int k = 1; k < T; k++) {
		//참조를 통한 생성을 막기위해 먼저 count를 확인한다.(메모리 초과 방지)
		if (A_data.count(k) && B_data.count(T - k)) {
			printf("A_data %d : %d, B_data %d : %d\n", k, A_data.count(k), T - k, B_data.count(T - k));
			ans += (long long)((long long)A_data[k] * (long long)B_data[T - k]);
		}
	}

	return ans;
}

int main() {
	scanf("%d", &T);
	scanf("%d", &A_size);
	subtotal_A.assign(A_size, 0);
	for (int k = 0; k < A_size; k++) {
		int a;
		scanf("%d", &a);
		subtotal_A[k] = (k == 0 ? a : subtotal_A[k - 1] + a);
	}
	scanf("%d", &B_size);
	subtotal_B.assign(B_size, 0);
	for (int k = 0; k < B_size; k++) {
		int b;
		scanf("%d", &b);
		subtotal_B[k] = (k == 0 ? b : subtotal_B[k - 1] + b);
	}

	printf("%lld\n", calculate());
}
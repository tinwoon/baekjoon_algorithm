//https://www.acmicpc.net/problem/10942
//틀린이유 -> 짝수일때도 팰린드롬이 성립한다는 것을 생각하지못해서 홀수일떄만 비교함

#include <iostream>
#include <vector>

std::vector<int> permutation;
std::vector< std::vector<int> >dp;
int num_permutation;
int num_problem;


bool same(int i, int j) {
	if (i == j) return true;
	else return false;
}

void calculate() {
	for (int i = 1; i <= num_permutation; i++) {
		dp[i][i] = 1;
		if (i != num_permutation) {
			if (permutation[i] == permutation[i + 1]) {
				dp[i][i + 1] = 1;
			}
		}
	}

	for (int i = 1; i <= num_permutation; i++) {
		for (int j = 1; j <= num_permutation / 2; j++) {
			if (i - j >= 1 && i + j <= num_permutation) {
				dp[i - j][i + j] = dp[i - j + 1][i + j - 1] && same(permutation[i - j],permutation[i + j]);
			}
			if (i - j >= 1 && i + 1 + j <= num_permutation) {
				dp[i - j][i + 1 + j] = dp[i - j + 1][i + 1 + j - 1] && same(permutation[i - j], permutation[i + 1 + j]);
			}
		}
	}
	

}



int main() {
	
	scanf("%d", &num_permutation);
	permutation.assign(num_permutation + 1, 0);
	dp.assign(num_permutation + 1, std::vector<int>(num_permutation + 1, 0));
	for(int i=1; i<=num_permutation; i++) {
		scanf("%d", &permutation[i]);
	}
	calculate();
	scanf("%d", &num_problem);
	while (num_problem--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}

}


#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

std::string data;
//N, 이전 값이 모음인지 아닌지, 이전 값의 이전 값, L 포함 여부
long long dp[101][3][3][2];
int vowels[5] = { 'A', 'E', 'I', 'O', 'U' };


long long calculate(int n, int p1, int p2, int l) {
	if (dp[n][p1][p2][l] != -1) return dp[n][p1][p2][l];

	if (n == data.size()) {
		return l;
	}

	long long ans = 0;
	//빈칸일 경우
	if (data[n] == '_') {
		//모음
		if (p1 == p2 && p1 == 1) {
		}
		else {
			ans += 5 * calculate(n + 1, p2, 1, l);
		}

		//자음
		if (p1 == p2 && p1 == 2) {
		}
		else {
			if (!l) ans += calculate(n + 1, p2, 2, 1);
			ans += (21 - (!l)) * calculate(n + 1, p2, 2, l);
		}
	}
	else {
		bool is_v = false;
		for (int k = 0; k < 5; k++) {
			if (vowels[k] == data[n]) {
				is_v = true;
				break;
			}
		}
		
		//모음
		if (is_v) {
			if (p1 == p2 && p1 == 1) {
			}else ans += calculate(n + 1, p2, 1, l);
		}
		//자음
		else {
			if (p1 == p2 && p1 == 2) {
			}else ans += calculate(n + 1, p2, 2, data[n] == 'L' || l);
		}
	}
	return dp[n][p1][p2][l] = ans;
}

int main() {
	std::cin >> data;
	memset(dp, -1, sizeof(dp));
	
	printf("%lld\n", calculate(0, 0, 0, 0));
}

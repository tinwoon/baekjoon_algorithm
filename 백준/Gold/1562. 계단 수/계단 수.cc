#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

#define DIV 1000000000

int N;

//length, number, visited
std::vector< std::vector < std::vector<int> > > dp;

void init() {
	for (int v = 0; v <= 9; v++) {
		dp[1][v][1 << v] = 1;
	}
}

int calculate() {
	int ret = 0;

	for (int length = 2; length <= N; length++) {
		for (int v = 0; v <= 9; v++) {
			for (int bit = 1; bit < (1 << 10); bit++) {
				if (bit & 1 << v) {
					if (v - 1 >= 0) {
						dp[length][v][bit] += (( (dp[length - 1][v - 1][bit]%DIV) + (dp[length - 1][v - 1][bit & ~(1 << v)]%DIV) )%DIV);
					}
					if (v + 1 <= 9) {
						dp[length][v][bit] += (((dp[length - 1][v + 1][bit] % DIV) + (dp[length - 1][v + 1][bit & ~(1 << v)] % DIV)) % DIV);
					}
					dp[length][v][bit] %= DIV;
				}
			}
		}
	}
	for (int v = 1; v <= 9; v++) {
		ret += (dp[N][v][(1 << 10) - 1]) % DIV;
		ret %= DIV;
	}

	return ret;
}

int main() {
	scanf("%d", &N);

	dp.assign(N + 1, std::vector< std::vector<int> >(10, std::vector<int>((1<<10), 0)));
	init();
	printf("%d", calculate());
}
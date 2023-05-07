#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

std::string data, angel, devil;
//dp[is_angel][idx][s_idx] : is_angel의 다리에서 idx번째일때의 최대 값, 
//is_angel : 천사인지 아닌지, idx : 탐구하고자 하는 문자열, s_idx : 현재 data의 찾고자하는 idx
std::vector< std::vector< std::vector<int> > > dp;
int ret = 0;

//is_angel이고, index이고, d_idx인 것부터 찾아보겠다.
int calculate(bool is_angel, int idx, int d_idx) {
	if (d_idx == data.size()) return 1;

	if (dp[is_angel][idx][d_idx] != -1) return dp[is_angel][idx][d_idx];

	int ans = 0;
	std::string brdg = is_angel ? angel : devil;
	auto fd_idx = std::find(brdg.begin() + idx, brdg.end(), data[d_idx]);
	while (fd_idx != brdg.end()) {
		ans += calculate((bool)(!is_angel), std::distance(brdg.begin(), fd_idx) + 1, d_idx + 1);
		fd_idx = std::find(fd_idx + 1, brdg.end(), data[d_idx]);
	}

	return dp[is_angel][idx][d_idx] = ans;
}

int main() {
	std::cin >> data >> angel >> devil;
	dp.assign(2, std::vector< std::vector<int> >(angel.size() + 1, std::vector<int>(data.size() + 1, -1)));

	printf("%d\n", calculate(1, 0, 0) + calculate(0, 0, 0));
}
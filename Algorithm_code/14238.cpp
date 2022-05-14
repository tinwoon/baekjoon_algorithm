#include <iostream>
#include <algorithm>

int a_size = 0;
int b_size = 0;
int c_size = 0;
int dp[51][51][51][51][4][4];
std::string ans;

bool calculate(int begin, int a, int b, int c, char before, char bbefore)
{
	if (a == 0 && b == 0 && c == 0)
	{
		return true;
	}
	if (dp[begin][a][b][c][(before - 'A') % 4][(bbefore - 'A') % 4]) return false;

	dp[begin][a][b][c][(before - 'A') % 4][(bbefore - 'A') % 4] = true;

	if (a > 0) {
		ans[begin] = 'A';
		if (calculate(begin + 1, a - 1, b, c, 'A', before)) return true;
	}

	if (b > 0 && before != 'B') {
		ans[begin] = 'B';
		if (calculate(begin + 1, a, b - 1, c, 'B', before)) return true;
	}
	if (c > 0 && before != 'C' && bbefore != 'C') {
		ans[begin] = 'C';
		if (calculate(begin + 1, a, b, c - 1, 'C', before)) return true;
	}
	return false;
}
int main()
{

	std::string a;
	std::cin >> a;

	ans.assign(a.size(), 0);
	for (auto it = a.begin(); it != a.end(); it++) {
		if (*it == 'A') a_size++;
		if (*it == 'B') b_size++;
		if (*it == 'C') c_size++;
	}

	if (calculate(0, a_size, b_size, c_size, ' ', ' '))
	{
		std::cout << ans;
	}
	else
		std::cout << -1;

}

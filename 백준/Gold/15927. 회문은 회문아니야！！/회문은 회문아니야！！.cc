#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::string str;
int ans = -1;

void calculate(int left, int right) {
	if (left > right) return;

	int start = left, end = right;
	std::set<int> count;

	while (start <= end) {
		if (str[start] != str[end]) {
			ans = right - left + 1;
			return;
		}
		start++; end--;
		count.emplace(str[start]);
		count.emplace(str[end]);
	}

	if (count.size() == 1) return;
	calculate(left + 1, right);
	calculate(left, right - 1);

}

int main() {
	std::cin >> str;
	calculate(0, str.size() - 1);
	printf("%d", ans);
}
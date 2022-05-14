#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>

//1509 �Ӹ���� ����
//���� ����� �κ��� ������.

std::string input;
std::vector< std::vector<int> > dp;

void calculate() {
	for (int i = 0; i < input.size(); i++) {
		dp[i][i] = 1;
		for (int j = i + 1; j < input.size(); j++) {
			int begin = i;
			int end = j;
			bool is_palindrom = true;
			while (begin <= end) {
				if (input[begin] != input[end]) {
					is_palindrom = false;
					break;
				}
				begin++;
				end--;
			}
			if (is_palindrom) dp[i][j] = 1;
		}
	}
	for (int i = 0; i < input.size() - 1; i++) {
		for (int j = i; j < input.size(); j++) {
			dp[0][j] = std::min(dp[0][j], dp[0][i] + dp[i + 1][j]);
		}
	}
	printf("%d", dp[0][input.size() - 1]);
}

int main() {
	std::cin >> input;
	dp.assign(input.size(), std::vector<int>(input.size(), 3000));
	calculate();
}
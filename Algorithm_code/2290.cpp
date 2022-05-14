//https://www.acmicpc.net/problem/2290
//아무리 생각해도 시뮬만큼 어려운 건 세상에 없다.

#include <iostream>
#include <vector>
#include <string>

int digit[10] = { 119,36,93,109,46,107,123,37,127,111 };
int s;
std::string n;

int main() {
	std::cin >> s;
	std::cin >> n;
	int digit_num = 0;
	for (int i = 0; i < 2 * s + 3; i++) {
		for (int k = 0; k < n.size(); k++) {
			for (int j = 0; j < s + 2; j++) {
				if (i == 0 || i == s + 1 || i == 2 * s + 2) {
					if (j == 0 || j == s + 1) {
						printf(" ");
						continue;
					}

					//n번째 숫자의 0번 lcd가 1이면
					if (digit[n[k] - '0'] & (1 << digit_num)) printf("-");
					else printf(" ");
				}
				else {
					if (j == 0 || j == s + 1) {
						if (digit[n[k] - '0'] & (1 << digit_num)) printf("|");
						else printf(" ");
						digit_num = j == 0 ? digit_num + 1 : digit_num - 1;
						continue;
					}
					else printf(" ");
				}
			}
			printf(" ");
		}
		if (i == 0 || i == s + 1 || i == 2 * s + 2) digit_num++;
		else if (i == s || i == 2 * s + 1) digit_num += 2;
		printf("\n");
	}
}

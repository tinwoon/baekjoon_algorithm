//이 is_ok알고리즘은 평생을 유용하게 쓸 듯
// 꼭 외워두 
#include <iostream>
#include <vector>
#include <string>

int C, P;
std::vector<int> map;

int is_ok(int i, std::string s) {
	if (i + s.size() -1 >= C) return 0;
	int base = map[i] - s[0] - '0';
	for (int k = 0; k < s.size(); k++) {기 
		if (base != map[i + k] - s[k] - '0') return 0;
	}
	return 1;
}

int calculate(int P) {
	int ans = 0;
	for (int i = 0; i < C; i++) {
		if (P == 1) {
			ans += is_ok(i, "0") + is_ok(i, "0000");
		}
		else if (P == 2) {
			ans += is_ok(i, "00");
		}
		else if (P == 3) {
			ans += is_ok(i, "001") + is_ok(i, "10");
		}
		else if (P == 4) {
			ans += is_ok(i, "100") + is_ok(i, "01");
		}
		else if (P == 5) {
			ans += is_ok(i, "000") + is_ok(i, "10") + is_ok(i, "101") + is_ok(i, "01");
		}
		else if (P == 6) {
			ans += is_ok(i, "000") + is_ok(i, "00") + is_ok(i, "011") + is_ok(i, "20");
		}
		else if (P == 7) {
			ans += is_ok(i, "000") + is_ok(i, "00") + is_ok(i, "110") + is_ok(i, "02");
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &C, &P);
	map.assign(C, 0);
	for (int i = 0; i < C; i++) {
		scanf("%d", &map[i]);
	}
	printf("%d", calculate(P));
}

#include <iostream>
#include <vector>
#include <string>

//KMP 알고리즘
//문자열 search 알고리즘이다.
//잘 기억해두자. 

std::string s;
std::string p;
std::vector<int> pi;
std::vector<int> ans;

void getpi() {
	pi.assign(p.size(), 0);
	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return;
}

void calculate() {
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == p.size() - 1) {
				ans.emplace_back(i - j);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	std::getline(std::cin, s);
	std::getline(std::cin, p);
	getpi();
	calculate();
	printf("%d\n", ans.size());
	for (int k = 0; k < ans.size(); k++) {
		printf("%d\n", ans[k] + 1);
	}
}

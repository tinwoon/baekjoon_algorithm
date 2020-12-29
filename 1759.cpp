#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string alphabet;
char vowel[5] = { 'a','e','i','o','u' };
int L, C;

//재귀 이용했어용

void calculate(int index, std::string tmp,int start) {
	if (index == L) {
		int count = 0;
		for (char vowel_value : vowel) {
			 count += std::count(tmp.begin(), tmp.end(), vowel_value);
		}
		if (0 < count && count <= L - 2) {
			std::cout << tmp << std::endl;
		}
		return;
	}

	for (int i = start; i < C; i++) {
		if (!std::count(tmp.begin(), tmp.end(), alphabet[i])) {
			calculate(index + 1, tmp + alphabet[i], i);
		}
	}
}




int main() {
	
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		char data;
		std::cin >> data;
		alphabet.push_back(data);
	}
	sort(alphabet.begin(), alphabet.end());
	calculate(0, "", 0);
}


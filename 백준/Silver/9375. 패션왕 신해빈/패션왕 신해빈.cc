#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int T, N;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while (T--) {
		int ret = 1;
		std::map< std::string, int > cloth_num;

		std::cin >> N;
		
		for (int k = 0; k < N; k++) {
			std::string cloth, cloth_type;
			std::cin >> cloth >> cloth_type;
			cloth_num[cloth_type]++;
		}

		for (auto itr = cloth_num.begin(); itr != cloth_num.end(); itr++) {
			ret *= ((itr->second) + 1);
		}

		printf("%d\n", ret - 1);
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> value;

//std 내장함수 활용

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		value.push_back(i);
	}

	do {
		for (int i = 0; i < value.size(); i++) {
			printf("%d ", value[i]);
		}
		printf("\n");
	} while (std::next_permutation(value.begin(), value.end()));
	

}

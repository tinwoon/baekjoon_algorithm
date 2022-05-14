#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

std::vector<int> value;
int sum;
//std 내장함수 활용

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		value.push_back(tmp);
	}
	sort(value.begin(), value.end());

	do {
		int data = 0;
		for (int i = 0; i < n - 1; i++) {
			data += abs(value[i] - value[i + 1]);
		}
		sum = std::max(data,sum);
	} while (std::next_permutation(value.begin(), value.end()));
	printf("%d", sum);
}

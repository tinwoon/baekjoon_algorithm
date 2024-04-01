#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> minus_a_b, plus_a_b;

int calculate() {


	std::sort(minus_a_b.begin(), minus_a_b.end());
	std::sort(plus_a_b.begin(), plus_a_b.end());

	return std::max(std::abs(plus_a_b[N - 1] - plus_a_b[0]), std::abs(minus_a_b[N - 1] - minus_a_b[0]));

}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		minus_a_b.emplace_back(a - b);
		plus_a_b.emplace_back(a + b);
	}
	printf("%d", calculate());
}
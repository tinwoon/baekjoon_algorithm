#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int N;
double sum = 0;
std::vector<int> data;

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout << std::fixed << std::setprecision(7);

	std::cin >> N;
	data.assign(N, 0);

	for (int k = 0; k < N; k++) {
		std::cin >> data[k];
		sum += data[k];
	}

	std::sort(data.begin(), data.end());

	std::cout << std::max((double)data[N - 2], (double)(sum / N));
}
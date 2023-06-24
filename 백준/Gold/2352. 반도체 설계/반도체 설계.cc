#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> data;
std::vector<int> LIS;

int calculate() {
	for (int k = 0; k < N; k++) {
		auto itr = std::lower_bound(LIS.begin(), LIS.end(), data[k]);
		if (itr == LIS.end()) {
			LIS.emplace_back(data[k]);
		}else{
			LIS[std::distance(LIS.begin(), itr)] = data[k];
		}
	}
	return LIS.size();
}

int main() {
	scanf("%d", &N);
	data.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &data[k]);
	}
	printf("%d", calculate());
}
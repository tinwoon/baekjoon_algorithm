#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> suffix_array;

//a가 b보다 사전 순으로 뒤에 있는지
bool is_behind(int a, int b) {
	int find_idx_a = -1, find_idx_b = -1;

	find_idx_a = std::find(suffix_array.begin(), suffix_array.end(), a) - suffix_array.begin();
	find_idx_b = std::find(suffix_array.begin(), suffix_array.end(), b) - suffix_array.begin();

	if (find_idx_a == suffix_array.size()) find_idx_a = -1;
	if (find_idx_b == suffix_array.size()) find_idx_b = -1;


	return find_idx_a < find_idx_b;
}

int calculate() {
	int ret = 1;

	for (int suffix_idx = 1; suffix_idx < N; suffix_idx++) {
		int prev_sffx_idx = suffix_idx - 1;
		
		if (!is_behind(suffix_array[prev_sffx_idx] + 1, suffix_array[suffix_idx] + 1)) ret++;
	}

	return ret;
}

int main() {
	scanf("%d", &N);
	suffix_array.assign(N, 0);

	for (int k = 0; k < N; k++) {
		scanf("%d", &suffix_array[k]);
	}

	printf("%d", calculate());
}
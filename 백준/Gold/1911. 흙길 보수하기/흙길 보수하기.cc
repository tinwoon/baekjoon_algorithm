#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int N, L;
std::vector< std::pair<int, int> > pools;

int calculate() {
	int panels = 0;
	int panels_endpoint = 0;
	std::sort(pools.begin(), pools.end());

	for (int k = 0; k < N; k++) {
		int start = std::max(pools[k].first, panels_endpoint);
		int end = pools[k].second;
		
		if (start < end) {
			int length = end - start;
			int panels_count = (length / L) + (length % L != 0);
			panels += panels_count;
			panels_endpoint = start + (panels_count * L);
		}
		
	}

	return panels;
}

int main() {
	scanf("%d %d", &N, &L);

	for (int k = 0; k < N; k++) {
		int start, end;
		scanf("%d %d", &start, &end);
		pools.emplace_back(std::pair<int, int>(start, end));
	}

	printf("%d", calculate());
}
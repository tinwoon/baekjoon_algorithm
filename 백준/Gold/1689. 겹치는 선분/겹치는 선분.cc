#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int N;
std::vector< std::pair<int, int> > dots;

int calculate() {
	int ans = 0, p_v = 0;
	std::sort(dots.begin(), dots.end());

	for (int k = 0; k < dots.size(); k++) {
		ans = std::max(ans, p_v += dots[k].second);
	}

	return ans;
}

int main() {
	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		int start, end;
		scanf("%d %d", &start, &end);

		dots.emplace_back(std::make_pair(start, 1));
		dots.emplace_back(std::make_pair(end, -1));
	}

	printf("%d\n", calculate());
}
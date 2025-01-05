#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int N;

std::vector< std::pair<int, int> > lines;

bool compare(std::pair<int, int>& a, std::pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int calculate() {
	std::sort(lines.begin(), lines.end(), compare);
	int length = 0, start = lines[0].first, end = lines[0].second;

	for (int k = 0; k < N; k++) {
		if (end < lines[k].first) {
			length += (end - start);
			start = lines[k].first;
			end = lines[k].second;
		}
		else {
			start = std::min(start, lines[k].first);
			end = std::max(end, lines[k].second);
		}
	}

	return length + (end - start);
}

int main() {
	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		int s, e;
		scanf("%d %d", &s, &e);

		lines.emplace_back(std::make_pair(s, e));
	}

	printf("%d\n", calculate());
}
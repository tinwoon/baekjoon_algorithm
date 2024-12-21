#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, length;
std::vector< std::pair<int, int> > line;

bool compare(std::pair<int, int>& a, std::pair<int, int>& b) {
	return a.second < b.second;
}

int calculate() {
	int ans = (line[0].second - line[0].first <= length);
	std::sort(line.begin(), line.end(), compare);

	std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int,int> > > pq;
	pq.emplace(line[0]);

	for (int k = 1; k < line.size(); k++) {
		if (line[k].second - line[k].first > length) continue;
		while (!pq.empty() && line[k].second - pq.top().first > length) {
			pq.pop();
		}
		pq.emplace(line[k]);
		ans = std::max(ans, (int)pq.size());
	}

	return ans;
}

int main() {
	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		int start, end;
		scanf("%d %d", &start, &end);
		if (start > end) std::swap(start, end);
		line.emplace_back(std::pair<int, int>(start, end));
	}
	scanf("%d", &length);

	printf("%d\n", calculate());
}
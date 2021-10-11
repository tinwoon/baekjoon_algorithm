#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

//inversion counting 변형 문제
//이전의 방문한 값을 보는게 오른쪽이 아니라 왼쪽을 기준으로 해야한다. (x축이 커지는 순이 아닌 작아지는 순이기 때문)

int T, n;
std::vector< std::pair<int, int> > data;
std::vector<int> y;

//data의 n번째 값이 어디에 있을까?
std::vector<int> x_to_y;
//tree
std::vector<long long> tree;

inline bool compare(std::pair<int, int>& a, std::pair<int, int>& b) {
	if (a.first > b.first) return true;
	else if (a.first == b.first) {
		if (a.second < b.second) return true;
		else return false;
	}
	else return false;
}

inline void update(int node, int start, int end, int index, int diff) {
	if (start > index || end < index) return;
	tree[node] += (long long)diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}

inline long long sum(int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

inline long long calculate(int n) {
	for (int k = 0; k < data.size(); k++) {
		auto itr = std::lower_bound(y.begin(), y.end(), data[k].second);
		x_to_y.emplace_back(std::distance(y.begin(), itr));
	}

	long long ans = 0;
	for (int k = 0; k < data.size(); k++) {
		ans += sum(1, 0, y.size() - 1, 0, x_to_y[k]);
		update(1, 0, y.size() - 1, x_to_y[k], 1);
	}
	return ans;
}





int main() {
	scanf("%d", &T);
	while (T--) {
		data.clear();
		y.clear();
		x_to_y.clear();
		tree.clear();
		scanf("%d", &n);

		std::set<int> y_tmp;
		for (int k = 0; k < n; k++) {
			int a, b;
			scanf("%d %d", &a, &b);
			data.emplace_back(std::make_pair(a, b));
			y_tmp.emplace(b);
		}
		y.assign(y_tmp.begin(), y_tmp.end());

		int size = ceil(log2(y.size())) + 1;
		tree.assign(1 << size, 0);

		std::sort(data.begin(), data.end(), compare);
		std::sort(y.begin(), y.end());
		printf("%lld\n", calculate(y.size()));
	}

}
#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

int T, N, L, K;
//loc, id, dir
std::vector<int> ID;
//loc
std::deque<int> left;
std::deque<int> right;

int calculate() 
{
	int l_idx = 0;
	int r_idx = ID.size() - 1;
	int ans = -1;
	while (K--) {
		if (!left.empty() && !right.empty()) {
			if (left.front() < abs(right.back() - L)) {
				if (K == 0) return ID[l_idx];
				l_idx++;
				left.pop_front();
			}
			else if (left.front() == abs(right.back() - L)) {
				if (K == 0) return ID[ID[l_idx] < ID[r_idx] ? l_idx : r_idx];
				if (ID[l_idx] < ID[r_idx]) {
					l_idx++; left.pop_front();
				}
				else {
					r_idx--; right.pop_back();
				}
			}
			else {
				if (K == 0) return ID[r_idx];
				r_idx--;
				right.pop_back();
			}
		}
		else if (!left.empty()) {
			if (K == 0) return ID[l_idx];
			l_idx++;
			left.pop_front();
		}
		else {
			if (K == 0) return ID[r_idx];
			r_idx--;
			right.pop_back();
		}
	}
	
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &N, &L, &K);
		ID.clear();
		left.clear();
		right.clear();
		for (int idx = 0; idx < N; idx++) {
			int loc, id;
			bool dir;
			scanf("%d %d", &loc, &id);
			if (id >= 0) dir = true;
			else dir = false;
			std::pair<int, int> dt = std::make_pair(loc, dir);
			ID.emplace_back(id);
			if (dir) {
				right.emplace_back(loc);
			}
			else left.emplace_back(loc);
		}
		printf("%d\n", calculate());
	}
}
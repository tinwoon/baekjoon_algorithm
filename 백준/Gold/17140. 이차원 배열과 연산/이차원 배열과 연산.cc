#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector< std::vector<int> > map(100, std::vector<int>(100, 0));
int r, c, k;
int max_r = 3, max_c = 3;

bool cmp(std::pair<int, int>& a, std::pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int calculate() {

	int TC = 0;

	while (TC < 101) {
		if (map[r - 1][c - 1] == k) return TC;

		//행 연산
		if (max_r >= max_c) {
			int n_max_c = 0;
			for (int i = 0; i < max_r; i++) {
				std::map<int, int> data;
				std::vector< std::pair<int, int> > s_v;
				for (int j = 0; j < max_c; j++) {
					if(map[i][j] != 0) data[map[i][j]]++;
				}
				s_v.assign(data.begin(), data.end());
				std::sort(s_v.begin(), s_v.end(), cmp);
				n_max_c = std::max((int)s_v.size() * 2, n_max_c);
				std::fill(map[i].begin(), map[i].begin() + max_c, 0);
				for (int j = 0; (j < s_v.size()) && (j < 50); j++) {
					map[i][j * 2] = s_v[j].first;
					map[i][j * 2 + 1] = s_v[j].second;
				}
			}
			max_c = n_max_c;
		}
		//열 연산
		else {
			int n_max_r = 0;
			for (int j = 0; j < max_c; j++) {
				std::map<int, int> data;
				std::vector< std::pair<int, int> > s_v;
				for (int i = 0; i < max_r; i++) {
					if (map[i][j] != 0) data[map[i][j]]++;
				}
				s_v.assign(data.begin(), data.end());
				std::sort(s_v.begin(), s_v.end(), cmp);
				n_max_r = std::max((int)s_v.size() * 2, n_max_r);
				for (int i = 0; i < max_r; i++) map[i][j] = 0;
				for (int i = 0; (i < s_v.size()) && (i < 50); i++) {
					map[i * 2][j] = s_v[i].first;
					map[i * 2 + 1][j] = s_v[i].second;
				}
			}
			max_r = n_max_r;
		}
		TC++;
	}
	
	return -1;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", calculate());
}
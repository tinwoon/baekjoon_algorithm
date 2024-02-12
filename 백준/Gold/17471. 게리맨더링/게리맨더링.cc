#pragma warning (disable : 4996)
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

int N;
std::vector<int> people;
std::vector< std::vector<bool> > connected;

int cal_diff(std::vector<int>& grps_one, std::vector<int>& grps_zero) {
	int grps_one_v = 0, grps_zero_v = 0;

	for (int k = 0; k < grps_one.size(); k++) {
		grps_one_v += people[grps_one[k]];
	}

	for (int k = 0; k < grps_zero.size(); k++) {
		grps_zero_v += people[grps_zero[k]];
	}

	return std::abs(grps_one_v - grps_zero_v);
}

bool is_grps(std::vector<int>& grps, int grps_min_node) {

	if (grps.size() == 0) return false;

	int count = 1;
	std::queue<int> q;
	std::vector<bool> visited(N, false);
	visited[grps_min_node] = true;
	q.emplace(grps_min_node);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int k = 0; k < grps.size(); k++) {
			if (!visited[grps[k]] && connected[node][grps[k]]) {
				q.emplace(grps[k]);
				visited[grps[k]] = true;
				count++;
			}
		}
	}

	return count == grps.size();
}

int calculate() {
	int diff = INT_MAX;
	for (int grps = 1; grps <= ((1 << N) - 1); grps++) {

		std::vector<int> grps_one, grps_zero;
		std::vector<bool> visited_grps;
		int grps_one_min_node = INT_MIN, grps_zero_min_node = INT_MIN;

		for (int bit = 0; bit < N; bit++) {
			if (grps & (1 << bit)) {
				grps_one.emplace_back(bit);
				if (grps_one_min_node == INT_MIN) grps_one_min_node = bit;
			}
			else {
				grps_zero.emplace_back(bit);
				if (grps_zero_min_node == INT_MIN) grps_zero_min_node = bit;
			}
		}

		if (is_grps(grps_one, grps_one_min_node) && is_grps(grps_zero, grps_zero_min_node)) {
			diff = std::min(diff, cal_diff(grps_one, grps_zero));
		}
	}

	return diff != INT_MAX ? diff : -1;
}

int main() {
	scanf("%d", &N);
	people.assign(N, 0);
	connected.assign(N, std::vector<bool>(N, 0));
	
	for (int k = 0; k < N; k++) {
		scanf("%d", &people[k]);
	}

	for (int i = 0; i < N; i++) {
		int count;
		scanf("%d", &count);
		for (int j = 0; j < count; j++) {
			int connected_node;
			scanf("%d", &connected_node);
			connected[i][connected_node - 1] = true;
		}
	}

	printf("%d", calculate());

}
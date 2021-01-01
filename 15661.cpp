#include <iostream>
#include <vector>
#include <queue>

int N;
int rst = 1000000000;
std::vector< std::vector<int> >map;

int calculate() {

	for (int i = 0; i < 1<<N; i++) {
		int value = 0;
		std::vector<int> team1;
		std::vector<int> team2;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) team1.push_back(j);
			else team2.push_back(j);
		}

		for (int a = 0; a < team1.size(); a++) {
			for (int b = a + 1; b < team1.size(); b++) {
				value += map[team1[a]][team1[b]] + map[team1[b]][team1[a]];
			}
		}
		for (int a = 0; a < team2.size(); a++) {
			for (int b = a + 1; b < team2.size(); b++) {
				value -= map[team2[a]][team2[b]] + map[team2[b]][team2[a]];
			}
		}
		value = std::abs(value);
		rst = std::min(rst, value);
	}
	return rst;
}

int main() {
	scanf("%d", &N);
	map.assign(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d", calculate());
}

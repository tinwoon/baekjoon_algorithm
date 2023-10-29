#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <algorithm>

int N;
std::vector< std::vector<int> > map;
int whole_population;

std::set< std::pair<int, int> > section(int x, int y, int d1, int d2, std::set< std::pair<int, int> >& data) {

	int nx = x, ny = y;

	for (int k = 0; k < d1; k++) {
		data.emplace(++nx, --ny);
	}
	for (int k = 0; k < d2; k++) {
		data.emplace(++nx, ++ny);
	}
	for (int k = 0; k < d1; k++) {
		data.emplace(--nx, ++ny);
	}
	for (int k = 0; k < d2; k++) {
		data.emplace(--nx, --ny);
	}

	return data;
}

int calculate() {

	int ans = INT_MAX;

	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {

					if ((i + d1 + d2 >= N) || (j - d1 < 0) || (j + d2 >= N)) continue;

					int population[6] = { 0, };

					int max_v, min_v;
					std::set< std::pair<int, int> > data;
					section(i, j, d1, d2, data);

					//1
					for (int x = 0; x < i + d1; x++) {
						for (int y = 0; y <= j; y++) {
							if (!data.count(std::make_pair(x, y))) {
								population[1] += map[x][y];
							}
							else break;
						}
					}

					//2
					for (int x = 0; x <= i + d2; x++) {
						for (int y = N - 1; y >= j + 1; y--) {
							if (!data.count(std::make_pair(x, y))) {
								population[2] += map[x][y];
							}
							else break;
						}
					}

					//3
					for (int x = N - 1; x >= i + d1; x--) {
						for (int y = 0; y < j - d1 + d2; y++) {
							if (!data.count(std::make_pair(x, y))) {
								population[3] += map[x][y];
							}
							else break;
						}
					}

					//4
					for (int x = N - 1; x >= i + d2 + 1; x--) {
						for (int y = N - 1; y >= j + d2 -d1; y--) {
							if (!data.count(std::make_pair(x, y))) {
								population[4] += map[x][y];
							}
							else break;
						}
					}

					population[5] = whole_population - population[1] - population[2] - population[3] - population[4];

					max_v = std::max({ population[1], population[2], population[3], population[4], population[5]});
					min_v = std::min({ population[1], population[2], population[3], population[4], population[5]});

					ans = std::min(ans, max_v - min_v);
				}
			}
		}
	}

	return ans;
}


int main() {
	scanf("%d", &N);
	map.assign(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			whole_population += map[i][j];
		}
	}

	printf("%d", calculate());
}
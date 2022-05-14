//https://www.acmicpc.net/problem/5213
//진짜 내가 할 수 있는 모든 머리의 집합체였다
//특별한 알고리즘은 없지만 reverse iterator 기억하기. 

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

int N;
int tile_size;
std::vector< std::pair<int, int> > tile;
std::vector<bool> visited;
std::vector<int> cant_first;
std::vector<int> cant_second;
std::vector<bool> is_Hollwo;
std::vector<bool> is_not_Hollow;
std::vector<int> from;

std::pair<int,int> final;



void print_from(int final){
	std::vector<int> data;
	data.emplace_back(final);
	while (final != 1) {
		final = from[final];
		data.emplace_back(final);
	}
	for (auto itr = data.rbegin(); itr != data.rend(); itr++) {
		printf("%d ", *itr);
	}
}

int calculate(int dx[], int dy[]) {
	//(1,1) 첫번째 타일이 1번째 방문이다.
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(1, 1));
	visited[1] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int tile_num;
		int num_cross_tile;
		tile_num = front.first;
		num_cross_tile = front.second;

		if (final.first <= tile_num) {
			final = std::make_pair(tile_num, num_cross_tile);
		}
		if (tile_num == std::pow(N, 2) - (N / 2)) return num_cross_tile;
		
		for (int k = 0; k < 3; k++) {
			int nx = tile_num + dx[k];
			if (nx <= tile_size && nx >= 1) {
				if (k == 2 && std::count(cant_first.begin(), cant_first.end(), tile_num)) continue;
				if ((k == 0 || k == 1) && (tile_num - 1) % (2 * N - 1) == 0) continue;
				if (!visited[nx] && tile[tile_num].first == tile[nx].second) {
					visited[nx] = true;
					q.emplace(std::make_pair(nx, num_cross_tile + 1));
					from[nx] = tile_num;
				} 
			}
		}

		for (int k = 0; k < 3; k++) {
			int ny = tile_num + dy[k];
			if (ny <= tile_size && ny >= 1) {
				if (k == 2 && std::count(cant_second.begin(), cant_second.end(), tile_num)) continue;
				if ((k == 0 || k == 1) && (tile_num - N) % (2 * N - 1) == 0) continue;
				if (!visited[ny] && tile[tile_num].second == tile[ny].first) {
					visited[ny] = true;
					q.emplace(std::make_pair(ny, num_cross_tile + 1));
					from[ny] = tile_num;
				}
			}
		}
		
	}

	return final.second;
}

int main() {
	scanf("%d", &N);
	tile_size = std::pow(N, 2) - (N / 2);
	visited.assign(tile_size + 1, false);
	tile.assign(tile_size + 1, std::pair<int, int>(0,0));
	from.assign(tile_size + 1, -1);
	//위 ,아래 한칸
	int dx[3] = { -N, N - 1 ,-1 };
	int dy[3] = { -(N - 1), N, 1 };

	int first = 1;
	int second = N;
	bool first_flag = false;
	bool second_flag = false;

	for (int i = 1; i <= tile_size; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		tile[i] = std::make_pair(a, b);
		if (i == first) {
			cant_first.emplace_back(first);
			if (!first_flag) first += N;
			else first += N-1;
			first_flag = !first_flag;
		}
		if (i == second) {
			cant_second.emplace_back(second);
			if (!second_flag) second += N-1;
			else second += N;
			second_flag = !second_flag;
		}
	}
	printf("%d\n", calculate(dx,dy));
	print_from(final.first);

}


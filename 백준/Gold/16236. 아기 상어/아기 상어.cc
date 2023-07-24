#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits.h>

int N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1,0,1 };

int baby_shark_size = 2;
int baby_shark_eat_count = 0;

std::vector< std::vector<int> > map;
std::pair<int, int> baby_shark;
//N의 크기에 해당하는 물고기의 개수
int fish_count[7];
//N의 크기를 가진 물고기 중 a,b에 해당하는 물고기가 먹혔을 경우

//현재 상어 크기보다 작거나 같은 크기의 물고기가 더이상 없을 때
bool deserve_find() {
	for (int k = 0; k < baby_shark_size; k++) {
		if (fish_count[k] > 0) return true;
	}
	return false;
}

int calculate() {
	
	int cnt = 0;

	std::priority_queue< std::tuple<int, int, int>, std::vector< std::tuple<int, int, int> > , std::greater< std::tuple<int, int, int> > > same_loc;
	same_loc.emplace(std::make_tuple(baby_shark.first, baby_shark.second, cnt));

	while (deserve_find() && !same_loc.empty()) {

		int least_count = INT_MAX;
		std::vector< std::vector<bool> > visited(N, std::vector<bool>(N, false));
		std::queue< std::tuple<int, int, int> > q;

		auto front = same_loc.top();
		q.emplace(front);
		int shark_x, shark_y, shark_count;
		std::tie(shark_x, shark_y, shark_count) = front;
		while (!same_loc.empty()) same_loc.pop();
		visited[shark_x][shark_y] = true;

		if ((shark_x != baby_shark.first) || (shark_y != baby_shark.second)) {
			if ((map[shark_x][shark_y] > 0) && (map[shark_x][shark_y] < baby_shark_size)) {

				fish_count[map[shark_x][shark_y]]--;
				baby_shark_eat_count++;
				cnt = shark_count;
				map[shark_x][shark_y] = 0;

				if (baby_shark_eat_count == baby_shark_size) {
					baby_shark_size++;
					baby_shark_eat_count = 0;
				}
			}
		}

		while (!q.empty()) {
			int x, y, count;
			std::tie(x, y, count) = q.front();
			q.pop();

			if (count > least_count) break;

			if (map[x][y] < baby_shark_size && map[x][y] >= 1) {
				same_loc.emplace(x, y, count);
				least_count = count;
			}


			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (!visited[nx][ny] && baby_shark_size >= map[nx][ny]) {
						visited[nx][ny] = true;
						q.emplace(std::make_tuple(nx, ny, count + 1));
					}
				}
			}
		}
	}
	
	return cnt;
}

int main() {
	scanf("%d", &N);
	map.assign(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 6) {
				fish_count[map[i][j]]++;
			}
			else if (map[i][j] == 9) {
				baby_shark = std::make_pair(i, j);
				map[i][j] = 0;
			}
		}
	}
	printf("%d\n", calculate());
}
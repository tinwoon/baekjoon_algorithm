#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <math.h>

int N;
//N번 학생의 친구들 번호
std::vector< std::vector<int> > friends;
//friends 순서
std::vector<int> frnds;
std::vector< std::vector<int> > map;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0, -1, 0,1 };

int calculate() {
	int ans = 0;

	map[1][1] = frnds[1];

	for (int idx = 2; idx <= N * N; idx++) {

		int student = frnds[idx];

		std::priority_queue< std::tuple<int, int, int, int> > how_many_friend;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!map[i][j]) {
					int friend_count = 0, empty = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							if (map[nx][ny]) {
								if (std::count(friends[student].begin(), 
									friends[student].end(), map[nx][ny])) {
									friend_count++;
								}
							}
							else empty++;
						}
					}
					how_many_friend.emplace(std::make_tuple(friend_count, empty, -1 * i, -1 * j));
				}
			}
		}

		int friend_cnt, empty, x, y;
		std::tie(friend_cnt, empty, x, y) = how_many_friend.top();
		map[-1 * x][-1 * y] = student;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny]) {
						if (std::count(friends[map[i][j]].begin(),
							friends[map[i][j]].end(), map[nx][ny])) {
							cnt++;
						}
					}
				}
			}
			ans += std::pow(10, cnt - 1);
		}
	}

	return ans;
}

int main() {
	scanf("%d", &N);
	friends.assign(N * N + 1, std::vector<int>());
	map.assign(N, std::vector<int>(N, 0));
	frnds.emplace_back(-1);

	for (int k = 0; k < N * N; k++) {
		int student, a, b, c, d;
		scanf("%d %d %d %d %d", &student, &a, &b, &c, &d);
		frnds.emplace_back(student);
		friends[student].emplace_back(a);
		friends[student].emplace_back(b);
		friends[student].emplace_back(c);
		friends[student].emplace_back(d);
	}
	printf("%d", calculate());
}
#include <iostream>
#include <vector>
#include <deque>

int N, K, L;
std::pair<int, int> head(std::make_pair(1, 0));

std::vector< std::pair<int, int> > road;
std::vector< std::vector<int> >map;
std::vector< std::pair<int, char> > order;

//반시계순;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int calculate() {
	int time = 0;
	//dir이 0부터 시작해서 반시계방향 순임.
	int dir = 3;
	road.push_back(head);
	while (1) {
		time++;
		auto front = order.front();
		if (time == front.first + 1) {
			if (front.second == 'D') {
				dir = (dir + 3) % 4;
			}
			else dir = (dir + 5) % 4;
		}

		head.first = head.first + dx[dir];
		head.second = head.second + dy[dir];
		if (head.first >= 1 && head.first <= N && head.second >= 1 && head.second <= N && (map[head.first][head.second] != -1)) {
			if(std::count(road.begin(), road.end(), std::pair<int, int>(head.first, head.second))) return time;
			if (map[head.first][head.second] == 1) {
				road.push_back(std::make_pair(head.first, head.second));
			}
			else {
				road.push_back(std::make_pair(head.first, head.second));
				road.erase(road.begin(), road.begin() + 1);
			}
		}
		else return time;
	}
}

int main() {
	scanf("%d", &N);
	map.assign(N + 2, std::vector<int>(N + 2, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || i == N + 1|| j == 0 || j == N + 1) {
				map[i][j] = -1;
			}
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		order.push_back(std::make_pair(a,b));
	}
	printf("%d", calculate());
}

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <tuple>

//https://www.acmicpc.net/problem/6087
//틀릴뻔한 이유 첫번쨰: visited를 사용하면 push_back을 통해 거울값을 +1해서 넣더라도 
// 거울이 낮은 값이 나중에 접근하려하면 visited가 true가 되어있어서 참조하지 못함
// 예를 들면 백준의 예제에서 (5,3)에 해당하는 거울 값이 4로 방향은 위를 향한다.
// 이 때 왼쪽 방향인 (5,2)를 확인하고 visited[5][2]를 true로 하며 큐를 push_back으로 넣어서 우선순위를 뒤로 한다.
// 물론 q의 참조는 거울 값의 가중치가 4가 다 끝나고 되기는 하지만 visited[5][2]가 true가 되었기 때문에 
// (6,2)에서 위로 올라오는 가중치는 4임에도 불구하고 visited[5][2]가 true가 되어있어서 value[5][2]에 4를 넣지 못한다.
// 즉 거울을 더 적게 쓸 수 있음에도 방문을 늦게해 버린 탓에 참조자체를 하지 않고 정답을 구하지 못한다.
// 따라서 
//if (value[ny][nx] > -1 && value[ny][nx] < data + 1) {
//	continue;
//}
//위의 문을 통해서 value가 -1이면 방문하지 않은것, 이미 계산된 value값이 현재 구한 value값보다 작으면 무시하면 된다.
//이러면 현재구한 value값이 작으면 작은 값을 넣을 수 있다.

std::vector< std::vector<char> >map;
std::vector< std::pair<int, int> >laser;
//std::vector< std::vector<bool> >visited;
std::vector< std::vector<int> >value;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;

void bfs() {
	std::deque< std::tuple<int, int, int, int> > q;
	//이전에 탐색한 k의 값, 거울의 개수
	q.push_front(std::make_tuple(laser[0].first,laser[0].second, -1,0));
	//visited[laser[0].first][laser[0].second] = true;
	value[laser[0].first][laser[0].second] = 0;

	while (!q.empty()) {
		auto front = q.front();
		q.pop_front();
		int x, y, z, data;
		std::tie(x, y, z, data) = front;

		/*if (x == laser[1].first && y == laser[1].second) {
			printf("%d", value[0][0]);
			return data;
		}*/
		
		for (int k = 0; k < 4; k++) {
			int ny = x + dy[k];
			int nx = y + dx[k];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (map[ny][nx] == '*') continue;
				
				//이동한 방향이 같다면
				if (z == k) {
					if (value[ny][nx] > -1 && value[ny][nx]<data) {
						continue;
					}
					else {
						q.push_front(std::make_tuple(ny, nx, k, data));
						value[ny][nx] = data;
					}
				}
				else {
					if (value[ny][nx] > -1 && value[ny][nx] < data + 1) {
						continue;
					}
					else {
						q.push_back(std::make_tuple(ny, nx, k, data + 1));
						value[ny][nx] = data + 1;
					}
				}
			}
				
			
		}
	}

}

int main() {
	scanf("%d %d",&M, &N);
	map.assign(N, std::vector<char>(M, 0));
	//visited.assign(N, std::vector<bool>(M, false));
	value.assign(N, std::vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'C') laser.push_back(std::make_pair(i,j));
		}
	}
	bfs();
	printf("%d\n", value[laser[1].first][laser[1].second]-1);
}

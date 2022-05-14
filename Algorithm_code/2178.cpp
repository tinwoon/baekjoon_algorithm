#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
std::vector < std::vector<int> > map;
std::vector < std::vector<bool> > visited;
std::vector < std::vector<int> > value;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };



void bfs(int i, int j) {
	std::queue< std::pair<int,int> > q;
	q.push(std::make_pair<int,int>(0,0));
	visited[0][0] = true;
	value[0][0] = 1;

	while (!q.empty()) {

		int nx = q.front().first;
		int ny = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			
			if ((nx + dx[k] >= 0) && (nx + dx[k] < N) && (ny + dy[k] >=0 ) && (ny + dy[k] < M)) {
				if (map[nx+dx[k]][ny+dy[k]] && !visited[nx + dx[k]][ny + dy[k]]){
					q.push( std::pair<int, int>( nx+dx[k], ny+dy[k] ) );
					value[nx + dx[k]][ny + dy[k]] = value[nx][ny] + 1;
					visited[nx + dx[k]][ny + dy[k]] = true;
				}
			}

		}
	}
	
	
}



int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M,0));
	value.assign(N, std::vector<int>(M, 0));
	visited.assign(N, std::vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);

	printf("%d\n", value[N-1][M-1]);
}

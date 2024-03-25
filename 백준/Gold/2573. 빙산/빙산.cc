#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>

int N, M;
//ice의 총 개수
std::queue< std::pair<int, int> > q;
std::vector< std::vector<int> > map;
std::vector< std::vector<int> > melting_count;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void ices(int i, int j, std::vector< std::vector<bool> >& visited) {
	visited[i][j] = true;

	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!map[nx][ny]) {
				melting_count[i][j]++;
			}else {
				if (!visited[nx][ny]) ices(nx, ny, visited);
			}
		}
	}
}

//Ice마다 1초 뒤 얼마나 녹는지 초기화
//다만 초기 시작부터 빙산의 개수가 N개 이상이거니, 빙산 자체가 없는 경우 return false;
//Melting Count 초기화 완료했고, 빙산을 녹일 수 있는 경우 return true;
bool init_melting_count() {
	if (q.empty()) return false;
	std::vector< std::vector<bool> > visited(N, std::vector<bool>(M, false));
	bool one_ices = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] && !visited[i][j]) {
				if (one_ices) return false;
				ices(i, j, visited);
				one_ices = true;
			}
		}
	}
	return true;
}

int checking(int x, int y, std::vector< std::vector<bool> >& visited) {
	if (x == -1 && y == -1) return 0;
	
	int ret = 1;
	visited[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visited[nx][ny] && map[nx][ny]) {
				ret += checking(nx, ny, visited);
			}
		}
	}
	return ret;
}

int calculate() {
	//얼음마다 1년 뒤에 녹는 개수에 대한 초기화
	//다만 초기 시작부터 빙산의 개수가 N개 이상이면 return false 됨.
	if (!init_melting_count()) return 0;
	int year = 1;

	do {
		std::queue< std::pair<int, int> > n_q;
		std::vector< std::vector<int> > n_melting_count = melting_count;
		int ice_count;
		std::pair<int, int> ice_lh = std::make_pair(-1, -1);
		std::vector< std::vector<bool> > visited(N, std::vector<bool>(M, false));

		if (q.empty()) return 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//빙하를 녹인다.
			map[x][y] = ((map[x][y] - melting_count[x][y]) < 0) ? 0 : (map[x][y] - melting_count[x][y]);

			//빙하가 녹게되면, 다른 빙하들의 melting_count에 영향을 준다. 생각해보니, Turn이 끝난 뒤에 변경해야할 듯 => n_melting_count
			if (map[x][y] == 0) {
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if(map[nx][ny] != 0) n_melting_count[nx][ny] += 1;
					}
				}
				n_melting_count[x][y] = 0;
			}else n_q.emplace(std::make_pair(x, y));
		}

		if (n_q.empty()) return 0;

		ice_count = n_q.size();
		ice_lh = n_q.front();

		if (ice_count != checking(ice_lh.first, ice_lh.second, visited)) {
			return year;
		}

		q = n_q;
		melting_count = n_melting_count;
	} while (year++);

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M, 0));
	melting_count.assign(N, std::vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) q.emplace(std::make_pair(i, j));
		}
	}

	printf("%d", calculate());
}
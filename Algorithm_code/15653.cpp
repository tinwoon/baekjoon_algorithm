#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int N, M;
std::vector< std::vector<char> > map;
std::pair<int, int> Red;
std::pair<int, int> Blue;
std::pair<int, int> hole;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[10][10][10][10];
bool red_visit_hole = false;

//여기서 rst가 바로 true로 반환되어 버리는 문제가 생김
std::pair<bool, bool> go_to(int k, int R_nx, int R_ny, int B_nx, int B_ny, bool is_R_first) {
	
	bool R_is_ok = false;
	bool B_is_ok = false;

	if (is_R_first) {
		while (map[R_nx + dx[k]][R_ny + dy[k]] != '#') {
			R_nx += dx[k];
			R_ny += dy[k];
			if (map[R_nx][R_ny] == 'O') {
				R_nx = 0;
				R_ny = 0;
				R_is_ok = true;
				break;
			}
		} 
		while (map[B_nx + dx[k]][B_ny + dy[k]] != '#' && (R_nx != B_nx + dx[k] || R_ny != B_ny + dy[k]) ) {
			B_nx += dx[k];
			B_ny += dy[k];
			if (map[B_nx][B_ny] == 'O') {
				B_nx = 0;
				B_ny = 0;
				B_is_ok = true;
				break;
			}
		}
	}
	else {
		while (map[B_nx + dx[k]][B_ny + dy[k]] != '#') {
			B_nx += dx[k];
			B_ny += dy[k];
			if (map[B_nx][B_ny] == 'O') {
				B_nx = 0;
				B_ny = 0;
				B_is_ok = true;
				break;
			}
		}
		while (map[R_nx + dx[k]][R_ny + dy[k]] != '#' && (R_nx + dx[k] != B_nx || R_ny + dy[k] != B_ny)) {
			R_nx += dx[k];
			R_ny += dy[k];
			if (map[R_nx][R_ny] == 'O' ) {
				R_nx = 0;
				R_ny = 0;
				R_is_ok = true;
				break;
			}
		}
	}

	Red = std::make_pair(R_nx,R_ny);
	Blue = std::make_pair(B_nx, B_ny);
	return std::make_pair(R_is_ok, B_is_ok);
}

std::pair<bool, bool> direct(int k, std::tuple<int,int,int,int,int> front) {
	int R_nx, R_ny, B_nx, B_ny;
	int count;
	std::tie(R_nx, R_ny, B_nx, B_ny, count) = front;
	std::pair<bool,bool> rst;
	switch (k) {
		case 0:
			//빨간 구슬이 파란 구슬보다 위에 있다.
			if (R_nx < B_nx) rst = go_to(k, R_nx, R_ny, B_nx, B_ny, true);
			//파란 구슬이 빨간 구슬보다 위에 있다.
			else rst = go_to(k, R_nx, R_ny, B_nx, B_ny, false);
			break;
		case 1:
			//빨간 구슬이 파란 구슬보다 오른쪽에 있다.
			if (R_ny > B_ny) rst = go_to(k, R_nx, R_ny, B_nx, B_ny, true);
			//파란 구슬이 빨간 구슬보다 오른쪽에 있다.
			else rst = go_to(k, R_nx, R_ny, B_nx, B_ny, false);
			break;
		case 2:
			//빨간 구슬이 파란 구슬보다 아래에 있다.
			if (R_nx > B_nx) rst = go_to(k, R_nx, R_ny, B_nx, B_ny, true);
			//파란 구슬이 빨간 구슬보다 아래에 있다.
			else rst = go_to(k, R_nx, R_ny, B_nx, B_ny, false);
			break;
		case 3:
			//빨간 구슬이 파란 구슬보다 왼쪽에 있다.
			if (R_ny < B_ny) rst = go_to(k, R_nx, R_ny, B_nx, B_ny, true);
			//파란 구슬이 빨간 구슬보다 왼쪽에 있다.
			else rst = go_to(k, R_nx, R_ny, B_nx, B_ny, false);
			break;
	}

	return rst;
}


int calculate() {
	std::queue< std::tuple<int, int, int, int, int> > q;
	q.push(std::make_tuple(Red.first, Red.second, Blue.first, Blue.second, 0));
	visited[Red.first][Red.second][Blue.first][Blue.second] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			auto rst = direct(k, front);
			if (!rst.second) {
				if (rst.first) return std::get<4>(front) + 1;
				if (!visited[Red.first][Red.second][Blue.first][Blue.second]) {
					q.push(std::make_tuple(Red.first, Red.second, Blue.first, Blue.second, std::get<4>(front) + 1));
					visited[Red.first][Red.second][Blue.first][Blue.second] = true;
				}
			}
		}
	}

	return -1;

}


int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<char>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'R') Red = std::pair<int, int>(i, j);
			if (map[i][j] == 'B') Blue = std::pair<int, int>(i, j);
			if (map[i][j] == 'O') hole = std::pair<int, int>(i, j);
		}
	}
	printf("%d", calculate());
}

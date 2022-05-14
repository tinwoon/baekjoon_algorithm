#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector< std::vector<char> > map;
//door의 좌표
std::vector<int> door;
//거울과 문의 데이터가 순서대로 저장되어있음.
std::vector< std::pair<int, int> > data;
//data의 i,j의 값은 data_index[i][j]의 번호에 있다. 
std::vector< std::vector<int> > data_index;
//x 와 y가 연결되어있는가.
std::vector< std::vector<bool> > is_connected;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int calculate() {
	is_connected.assign(data.size(), std::vector<bool>(data.size(),false));
	for (int i = 0; i < data.size(); i++) {
		for (int k = 0; k < 4; k++) {
			int nx = data[i].first + dx[k];
			int ny = data[i].second + dy[k];

			while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] == '*') break;
				if (map[nx][ny] == '!' || map[nx][ny] == '#') {
					is_connected[i][data_index[nx][ny]] = true;
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}

	std::vector<int> visited(data.size(), -1);
	std::queue<int> q;
	q.emplace(door[0]);
	visited[door[0]] = 0;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		if (front == door[1]) return visited[door[1]];

		for (int i = 0; i < data.size(); i++) {
			if (is_connected[front][i] && visited[i] == -1) {
				q.emplace(i);
				visited[i] = visited[front] + 1;
			}
		}
	}

	
}

int main() {
	scanf("%d", &N);
	data_index.assign(N, std::vector<int>(N, 0));
	map.assign(N, std::vector<char>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '!') {
				data.emplace_back(std::make_pair(i,j));
				data_index[i][j] = data.size() - 1;
			}
			else if (map[i][j] == '#') {
				data.emplace_back(std::make_pair(i, j));
				door.emplace_back(data.size()-1);
				data_index[i][j] = data.size() - 1;
			}
		}
	}
	printf("%d", calculate()-1);
}


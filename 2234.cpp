//https://www.acmicpc.net/problem/2234
//성곽문제로 어려운 점은 없었다. 

#include <iostream>
#include <vector>
#include <queue>
#include <set>

int N, M;
std::vector< std::vector<int> > map;
std::vector< std::vector<bool> > visited;
std::vector< std::vector<int> > map_num;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };


std::pair< int, std::vector<int> > calculate() {

	int num_of_room = 0;
	//각 방 별로 방의 크기가 넣어져있는 벡터
	std::vector<int> room_size;
	visited.assign(N, std::vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			//방의 크기
			int room_size_value = 0;
			std::queue< std::pair<int, int> >q;
			visited[i][j] = true;
			map_num[i][j] = num_of_room;
			q.emplace(std::make_pair(i, j));

			while (!q.empty()) {
				auto front = q.front();
				q.pop();
				room_size_value++;

				for (int k = 3; k >= 0; k--) {
					int nx = front.first + dx[k];
					int ny = front.second + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (!visited[nx][ny] ) {
							if (map[front.first][front.second] & (1 << k)) continue;
							visited[nx][ny] = true;
							q.emplace(std::make_pair(nx, ny));
							map_num[nx][ny] = num_of_room;
						}
					}
				}
			}
			//방번호
			num_of_room++;
			room_size.emplace_back(room_size_value);
		}
	}
	
	return std::make_pair(num_of_room, room_size);
}

int if_deleted_wall(std::pair<int, std::vector<int>> rst) {
	int max = -1;
	std::vector<int> each_room_size = rst.second;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (map_num[i][j] == map_num[nx][ny]) continue;
					max = std::max(max, each_room_size[map_num[i][j]] + each_room_size[map_num[nx][ny]]);
				}
			}
		}
	}
	return max;
}

int main() {
	scanf("%d %d", &M, &N);
	map.assign(N, std::vector<int>(M, 0));
	map_num.assign(N, std::vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	auto rst = calculate();
	printf("%d\n%d\n", rst.first, *std::max_element(rst.second.begin(), rst.second.end()) );
	printf("%d", if_deleted_wall(rst));
}

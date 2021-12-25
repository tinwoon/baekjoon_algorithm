#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

//16932 ��� ����� ����
//�ܼ��� BFS�� �����¿쿡 �ִ� ������ ���� Ȯ���ϸ� �Ǵ� ����
//�ٸ� �����¿쿡 �ش��ϴ� ���� ���� ���� �� �ֱ⿡
//Visited �迭�� �� �б⸶�� �����ϴµ� �ƴ� Map�� �����Ͽ� ������ ȿ�������� ������ �� �ִ�. 

int N, M;
std::vector< std::vector<int> > map;
std::vector< std::vector<int> > map_id;
std::vector< std::vector<bool> > visited;
std::vector<int> id_size;
int ans;
int size_id;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int id_index = 1;

void calculate(int x, int y) {
	int size = 1;
	visited[x][y] = true;
	map_id[x][y] = id_index;
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(x, y));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = front.first + dx[k];
			int ny = front.second + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visited[nx][ny] && map[nx][ny]) {
					visited[nx][ny] = true;
					q.emplace(std::make_pair(nx, ny));
					map_id[nx][ny] = id_index;
					size++;
				}
			}
		}
	}

	id_index++;
	id_size.emplace_back(size);
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M, 0));
	map_id.assign(N, std::vector<int>(M, 0));
	visited.assign(N, std::vector<bool>(M, false));
	id_size.emplace_back(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j]) calculate(i, j);
		}
	}

	size_id = id_size.size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if(!map[i][j]){
				int sum = 0;
				std::map<int, bool> size_visited;

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (!size_visited.count(map_id[nx][ny])) {
							sum += id_size[map_id[nx][ny]];
							size_visited[map_id[nx][ny]] = true;
						}
					}
				}
				ans = std::max(ans, sum);
			}
		}
	}

	printf("%d", ans + 1);

}

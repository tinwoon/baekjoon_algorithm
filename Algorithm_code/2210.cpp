//https://www.acmicpc.net/problem/2210
// set을 통해 풀면 더 쉽게 할 수 있음.
// tuple을 네개 인자로 놓는 것 보단 dfs를 5*5번 수행하는 방식으로 하고 set을 통해 중복을 제거하는게 더 좋음. 

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

std::vector< std::vector<int> > map(5, std::vector<int>(5, 0));
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int calculate() {
	std::vector< std::vector<int> > rst;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int cnt = 0;
			std::queue< std::tuple<int, int, std::vector<int> > > q;
			std::vector<int> data;
			data.push_back(map[i][j]);
			q.push(std::make_tuple(i,j,data));
			
			while (!q.empty()) {
				auto front = q.front();
				int x, y;
				std::vector<int> z;
				std::tie(x, y, z) = front;
				q.pop();

				if (z.size()==6) {
					if (std::count(rst.begin(), rst.end(), z)) continue;
					rst.push_back(z);
					continue;
				}

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
						z.push_back(map[nx][ny]);
						q.push(std::make_tuple(nx, ny, z));
						z.pop_back();
					}
				}

			}

		}
	}

	return rst.size();
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", calculate());
}

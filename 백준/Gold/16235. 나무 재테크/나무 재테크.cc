#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

//N : 땅의 좌우 크기, M : 상도가 처음에 심은 나무, K : K 년도 후의 살아있는 나무의 개수
int N, M, K;
std::vector< std::vector<int> > map;
std::vector< std::vector<int> > p_map;
std::vector< std::vector<int> > d_map;

//x, y에 해당하는 곳에 나무의 나이들
std::vector< std::vector< std::deque<int> > > tree;

int dx[8] = { -1, 0 ,1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void TC() {

	std::vector < std::vector<int> > b_tree(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			std::deque<int> dq;

			while (!tree[i][j].empty()) {
				int tree_age = tree[i][j].front();
				tree[i][j].pop_front();

				if (p_map[i][j] >= tree_age) {
					p_map[i][j] -= tree_age;

					if ((tree_age + 1) % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int nx = i + dx[k];
							int ny = j + dy[k];
							if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
								b_tree[nx][ny]++;
							}
						}
					}
					dq.emplace_back(tree_age + 1);
				}
				else d_map[i][j] += (int)(tree_age / 2);
			}

			tree[i][j] = dq;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < b_tree[i][j]; k++) {
				tree[i][j].emplace_front(1);
			}
			p_map[i][j] += (map[i][j] + d_map[i][j]);
			d_map[i][j] = 0;
		}
	}
}



int calculate() {
	int ret = 0;

	while (K--) {
		TC();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += (tree[i][j].size());
		}
	}

	return ret;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	map.assign(N, std::vector<int>(N, 0));
	d_map.assign(N, std::vector<int>(N, 0));
	p_map.assign(N, std::vector<int>(N, 5));
	tree.assign(N, std::vector< std::deque<int> >(N, std::deque<int>()));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int k = 0; k < M; k++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		tree[x - 1][y - 1].emplace_back(z);
	}
	printf("%d", calculate());
}

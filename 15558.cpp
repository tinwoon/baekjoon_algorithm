#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

//이 문제 재밌네
int n, k;
std::vector< std::vector<int> > row;
std::vector< std::vector<bool> >visited;


bool bfs() {
	std::queue< std::tuple<int,int, int> > q;
	q.push(std::make_tuple(0,0,0));
	visited[0][0] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int x, y, z;
		std::tie(x, y, z) = front;

		if (y + 1 < n) {
			if (!visited[x][y + 1] && row[x][y + 1] == 1) {
				visited[x][y + 1] = true;
				q.push(std::make_tuple(x, y + 1, z + 1));
			}
		}
		else return true;

		if (y - 1 >= 0) {
			if (!visited[x][y - 1] && row[x][y - 1] == 1 && y - 1 > z) {
				visited[x][y - 1] = true;
				q.push(std::make_tuple(x, y - 1, z + 1));
			}
		}

		if (y + k < n) {
			if (!visited[!x][y + k] && row[!x][y + k] == 1) {
				visited[!x][y + k] = true;
				q.push(std::make_tuple(!x, y + k, z + 1));
			}
		}
		else return true;
		
		
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &k);
	visited.assign(2, std::vector<bool>(n, 0));
	for (int i = 0; i < 2; i++) {
		std::vector<int> tmp(n, 0);
		for (int j = 0; j < n; j++) {
			scanf("%1d", &tmp[j]);
		}
		row.push_back(tmp);
	}
	printf("%d", bfs());
}

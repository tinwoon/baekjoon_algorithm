#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> > map;
std::vector< std::vector<bool> >visited;
std::vector <int> rst;
int block_size = 0;
int n;


//틀렸던 이유 => map이 1일때만 방문했어야하는데 0일때도 방문함
void dfs(int i,int j) {

	
	if (map[i][j] && !visited[i][j]) block_size++;
	visited[i][j] = true;

	
	if (i - 1 >= 0) {
		if (map[i - 1][j] && !visited[i - 1][j]) {
			dfs(i - 1, j);
		}
	}
	if (j + 1 < n) {
		if (map[i][j + 1] && !visited[i][j + 1]) {
			dfs(i, j + 1);
		}
	}
	if (i + 1 < n) {
		if (map[i + 1][j] && !visited[i + 1][j]) {
			dfs(i + 1, j);
		}
	}
	if (j - 1 >= 0) {
		if (map[i][j - 1] && !visited[i][j - 1]) {
			dfs(i, j - 1);
		}
	}
	
}


int main() {
	scanf("%d", &n);
	map.assign(n, std::vector<int>(n, 0));
	visited.assign(n, std::vector<bool>(n, false));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			block_size = 0;
			if (map[i][j]) {
				dfs(i, j);
			}
			if(block_size) rst.push_back(block_size);
		}
	}
	std::sort(rst.begin(), rst.end());
	printf("%d\n", rst.size());
	for (int i = 0; i < rst.size(); i++) {
		printf("%d\n", rst[i]);
	}


}

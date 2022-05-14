#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

int N, M;
std::vector<int> value;
std::vector<bool> visited;
std::vector<int> permutation;

//dfs¿¡¼­ º»¶ä

void dfs(int i, int index, std::vector<int> &permutation) {

	if(i != -1) visited[i] = true;
	
	
	if (M == index) {
		for (int i = 0; i < M; i++) {
			printf("%d ", permutation[i]);
		}
		printf("\n");
	}

	for (int i = 0; i < value.size(); i++) {
		if (!visited[i]) {
			permutation.push_back(value[i]);
			dfs(i, index + 1, permutation);
			visited[i] = false ;
			permutation.pop_back();
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	visited.assign(N,false);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		value.push_back(tmp);
	}
	std::sort(value.begin(), value.end());
	dfs(-1, 0, permutation);
}

#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//1412 일방통행 문제
//방향이 변경 가능하다는 의미는 해당 간선을 통해서 싸이클을 절대적으로 만들 수 없음을 의미
//이는 해당 간선을 무시해도 된다는 의미와 동일하다.(단방향 간선만 고려해주면 된다는 의미)


int N;
bool ans;

std::vector< std::vector<bool> > map;
std::vector<bool> visited;
std::vector<bool> finished;

void calculate(int node) {
	visited[node] = true;

	for (int k = 0; k < N; k++) {
		if (map[node][k] && !visited[k]) calculate(k);
		else if (map[node][k] && !finished[k]) ans = true;
	}

	finished[node] = true;
}

int main() {
	scanf("%d", &N);
	map.assign(N, std::vector<bool>(N, false));
	visited.assign(N, false);
	finished.assign(N, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char v;
			scanf(" %1c", &v);
			if (v == 'Y') {
				if (map[j][i] == false) map[i][j] = true;
				else map[j][i] = false;
			}
		}
	}

	for (int node = 0; node < N; node++) {
		if (ans) break;
		if (!visited[node]) calculate(node);
	}

	printf("%s\n", ans ? "NO" : "YES");

}

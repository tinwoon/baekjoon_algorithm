#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>


//문제점 이미 방문된 노드인지 아니면 예전에 가던 경로에 저장된 내용인지 확인하지는 못하는 단점이 있다.
//예를 들어 1에서 3번노드를 간 뒤 3번에서 1번을 가면 안되는 용도로만 써야하는데 3번에서 1번을 가는 것을
//노드의 재방문이 아닌 이미 선정된 최고로 빠른 경로를 확인하는 것으로 생각하면 결국 답을 중복해서 찾는다.
//위의 예제에서는 1번 3번 4번 2번을 간 뒤에 4번 노드를 방문하는데 4번이 이미 dp값이 나와 있으므로
// 4번 값을 dp[node]를 해선 안되는데 하고 끝낸다.
// 즉, dp의 값이 -1이 아닌 상태를 경로의 재방문인지 아니면 최단 경로를 위한건지 구분할 수 없다.


int V;
//x,y 좌표가 연결되어 있는가
//std::map< std::pair<int,int>, bool> is_connected;
std::vector< std::vector< std::pair<int, int> > > is_connected;
int dp[100001];
bool visited[100001];
int ans = 0;

void dfs(int node, int rst) {

	if (visited[node]) return;

	if (dp[node] != -1) {
		ans = std::max(ans, rst + dp[node]);
		return;
	}

	visited[node] = true;
	dp[node] = rst;
	ans = std::max(ans, rst);

	for (int k = 0; k < is_connected[node].size(); k++) {
		dfs(is_connected[node][k].first, rst + is_connected[node][k].second);
	}
}

int main() {
	scanf("%d", &V);
	is_connected.assign(V + 1, std::vector< std::pair<int, int> >());
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < V; i++) {
		int v;
		scanf("%d", &v);
		while (1) {
			int a, b;
			scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			is_connected[v].emplace_back(std::make_pair(a, b));
		}
	}
	for (int k = 1; k < V; k++) {
		int rst = 0;
		dfs(k, rst);
	}
	printf("%d", ans);
}
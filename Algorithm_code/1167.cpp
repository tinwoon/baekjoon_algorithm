#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>


//Ʈ���� ������ ���� ���� �������� �ٸ� ������ �湮�ϸ� �Ǵ� �����̴�.
//���� ������ ������ ���� ���� ������ �ϳ� �湮�� ��, �ݴ��� ������ ã�ư��� �ȴ�.
int V;

std::vector< std::vector< std::pair<int, int> > > is_connected;
bool visited[100001];
int ans = 0;
int end_node = -1;

void dfs(int node, int rst) {
	if (ans <= rst) {
		ans = rst;
		end_node = node;
	}

	visited[node] = true;

	for (int i = 0; i < is_connected[node].size(); i++) {
		if (!visited[is_connected[node][i].first]) dfs(is_connected[node][i].first, rst + is_connected[node][i].second);
	}

}

int main() {
	scanf("%d", &V);
	is_connected.assign(V + 1, std::vector< std::pair<int, int> >());
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
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(end_node, 0);
	printf("%d", ans);
}
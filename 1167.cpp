#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>


//������ �̹� �湮�� ������� �ƴϸ� ������ ���� ��ο� ����� �������� Ȯ�������� ���ϴ� ������ �ִ�.
//���� ��� 1���� 3����带 �� �� 3������ 1���� ���� �ȵǴ� �뵵�θ� ����ϴµ� 3������ 1���� ���� ����
//����� ��湮�� �ƴ� �̹� ������ �ְ�� ���� ��θ� Ȯ���ϴ� ������ �����ϸ� �ᱹ ���� �ߺ��ؼ� ã�´�.
//���� ���������� 1�� 3�� 4�� 2���� �� �ڿ� 4�� ��带 �湮�ϴµ� 4���� �̹� dp���� ���� �����Ƿ�
// 4�� ���� dp[node]�� �ؼ� �ȵǴµ� �ϰ� ������.
// ��, dp�� ���� -1�� �ƴ� ���¸� ����� ��湮���� �ƴϸ� �ִ� ��θ� ���Ѱ��� ������ �� ����.


int V;
//x,y ��ǥ�� ����Ǿ� �ִ°�
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
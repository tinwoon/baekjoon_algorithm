#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//1516 ���Ӱ��� ����
//�������� DAG (���� ����) ���� ����
//����� �κ��� ������.

int N;
//N���� �������� ������ indegree
std::vector<int> indegree;
//N�� ����� indegree�� ������ node
std::vector< std::vector<int> > indegree_node;
//N�� ����� �ǹ� �Ѱ��� ��ġ�ϴµ� �ɸ��� �ð�
std::vector<int> take_time;
//N�� ����� �ǹ��� ��ġ�ϴµ� �ɸ��� �ð�
std::vector<int> ans;
//N�� ����� �ǹ��� �ʿ��� �ǹ���
std::vector< std::vector<int> > connected;

int ret_max(int node) {
	int ret = 0;

	for (int k = 0; k < indegree_node[node].size(); k++) {
		ret = std::max(ret, ans[indegree_node[node][k]]);
	}
	return ret;
}

void calculate() {
	std::queue<int> q;

	for (int k = 1; k <= N; k++) {
		if (!indegree[k]) {
			q.emplace(k);
			ans[k] = take_time[k];
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int k = 0; k < connected[node].size(); k++) {
			int n_node = connected[node][k];
			indegree[n_node]--;

			if (indegree[n_node] == 0) {
				ans[n_node] = take_time[n_node] + ret_max(n_node);
				q.emplace(n_node);
			}
		}
	}
	return;
}


int main() {
	scanf("%d", &N);
	take_time.assign(N + 1, 0);
	indegree.assign(N + 1, 0);
	ans.assign(N + 1, 0);
	indegree_node.assign(N + 1, std::vector<int>());
	connected.assign(N + 1, std::vector<int>());

	for (int k = 1; k <= N; k++) {
		int time;
		scanf("%d", &time);
		take_time[k] = time;
		while (1) {
			int n_node;
			scanf("%d", &n_node);
			if (n_node == -1) break;
			indegree[k]++;
			indegree_node[k].emplace_back(n_node);
			connected[n_node].emplace_back(k);
		}
	}

	calculate();

	for (int k = 1; k <= N; k++) {
		printf("%d\n", ans[k]);
	}
}
#pragma warning (disable: 4996)
#include <iostream>
#include <vector>
#include <queue>

int N;
//i�� �۾��� indegree ���� x���̴�.
int indegree[10001];
//i�� ��带 �������ڷ� ������ ����(i����尡 �־�� ������ �� �ִ� ���)
//i�� ��带 outdegree�� ������ ���
std::vector< std::vector<int> > indegree_node;
//�� ����� �۾� �ð��� ���ǵǾ� �ִ�.
int node_time[10001];


int calculate() {
	int rst = 0;
	//n�� ������ �����ϴµ� �ɸ��� �ð�
	int take_time[10001];
	std::queue<int> q;
	for (int k = 1; k <= N; k++) {
		take_time[k] = 0;
		if (indegree[k] == 0) {
			q.emplace(k);
			take_time[k] = node_time[k];
		}
	}

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		rst = std::max(take_time[front], rst);

		for (int index = 0; index < indegree_node[front].size(); index++) {
			//front�� indegree�� ������ ��� => node
			int node = indegree_node[front][index];
			take_time[node] = std::max(take_time[node], take_time[front]);
			indegree[node]--;
			if (indegree[node] == 0) {
				take_time[node] += node_time[node];
				q.emplace(node);
			}
		}
	}
	return rst;
}

int main() {
	int time, M;
	scanf("%d", &N);
	indegree_node.assign(N + 1, std::vector<int>(0, 0));
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &time, &M);
		node_time[i] = time;
		indegree[i] = M;
		for (int j = 0; j < M; j++) {
			int end_node;
			scanf("%d", &end_node);
			//end_node�� out_degree�� ������ ����
			indegree_node[end_node].emplace_back(i);
		}
	}
	printf("%d", calculate());
}
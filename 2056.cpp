#pragma warning (disable: 4996)
#include <iostream>
#include <vector>
#include <queue>

int N;
//i번 작업의 indegree 수는 x개이다.
int indegree[10001];
//i번 노드를 선행주자로 가지는 노드들(i번노드가 있어야 수행할 수 있는 노드)
//i번 노드를 outdegree로 가지는 노드
std::vector< std::vector<int> > indegree_node;
//각 노드의 작업 시간이 정의되어 있다.
int node_time[10001];


int calculate() {
	int rst = 0;
	//n번 노드까지 수행하는데 걸리는 시간
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
			//front를 indegree로 가지는 노드 => node
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
			//end_node를 out_degree로 가지는 노드들
			indegree_node[end_node].emplace_back(i);
		}
	}
	printf("%d", calculate());
}
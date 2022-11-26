#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>

//11438 LCA2 문제
//최소 공통 조상의 최적화 문제로 Sparse Table(희소 배열)이란 개념이 필요함
//플래 3이상은 되어야 된다 생각하는 문제
//희소 배열이란 Segment Tree와 비슷하게 1,2,4,8,16....번의 값을 기반으로 N번쨰 값을 찾기 위한 배열을 의미한다.
//ex) 특정 그래프에서 n번 노드로부터 15번째 간선을 지난 후의 노드를 알고싶다면
//15번을 dfs나 bfs로 15번 탐색할 수도 있지만,
//기존에 N번 노드로 부터 1번, 2번, 4번, 8번의 간선을 지난 노드를 저장한 배열(희소 배열)을 가지고 있다면
//8번 지난 노드 -> 4번 지난 노드 -> 2번 지난 노드 -> 1번 지난 노드 == 15번 지난 노드
//이런 식으로 15번 지난 노드를 4번의 연산만으로 구할 수 있다.
//현 문제의 경우도 LCA를 찾기 위해 Level을 올리는 단위가 한 level씩 올리며 찾는 방법이 있으나,(이 경우 시간초과)
//한번에 log(N)level 씩 올리면서 찾는 방법을 통해 최적화가 가능하다.
int N, M, lg, max_depth;

std::vector< std::vector<int> > connected;
std::vector<int> depth;
std::vector<int> parent;
std::vector<bool> visited;
//i번 노드에 2^j번 조상은 누구인가.
std::vector< std::vector<int> > p;

void init() {
	//노드 중 가장 깊이가 깊은 노드의 level = max_depth
	max_depth = *std::max_element(depth.begin(), depth.end());
	//lg = log2(가장 깊이가 깊은 depth)
	for (lg = 1; (1 << lg) <= max_depth; lg++);
	p.assign(N + 1, std::vector<int>(lg, 0));

	//맨 처음 한칸 위의(2^0 == 1)의 parent 조상 초기화
	for (int k = 1; k <= N; k++) {
		p[k][0] = parent[k];
	}

	//parent들의 조상 초기화 값 하기와 같음(ex : 4번째 위의 조상을 찾는 방법은 2번째 위의 조상의 2번째 위의 조상을 찾으면 된다.)
	for (int j = 1; j < lg; j++) {
		for (int i = 1; i <= N; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);

	//같은 높이까지 올려줌.
	for (int k = lg - 1; k >= 0; k--) {
		//2^k번째 조상이 0이 아닐때(Root 노드보다 위가 아닐 때)
		if (p[a][k] && (depth[p[a][k]] >= depth[b])) a = p[a][k];
	}

	//같은 높이까지 올린 노드가 만약 서로 일치한다면(b가 a의 자식노드였어서, 바로 올렸더니 일치했었다면)
	if (a == b) return a;

	for (int k = lg - 1; k >= 0; k--) {
		//2^k번째 조상이 Root노드보다 위가 아니고(존재하고), 2^k번째 조상이 같지 않다면
		//같아도 올리지 않는 이유는 1 -> 2 -> 3, 1 -> 2 -> 4로 된 트리가 있다고 가정했을 때,
		//3의 2^1번째 조상노드 => 1, 4의 2^1번째 조상노드 => 1 이므로 값이 공통된 조상이나 "최소"공통 조상이 아닌 케이스가 존재한다.(최소 공통조상은 여기서 2임)
		//따라서 공통조상이 아닌 경우까지만 최대한 올려주면 바로 그 위가 공통 조상임은 자명함으로 일치하지 않을 때 까지만 올려준다.
		if (p[a][k] && (p[a][k] != p[b][k])) {
			a = p[a][k];
			b = p[b][k];
		}
	}

	return parent[a];
}

void bfs() {
	//node, depth
	std::queue< std::pair<int, int> > q;

	visited[1] = true;
	q.emplace(std::make_pair(1, 0));

	while (!q.empty()) {
		auto queue = q.front();
		int node = queue.first;
		int dpth = queue.second;
		q.pop();


		for (int k = 0; k < connected[node].size(); k++) {
			int n_node = connected[node][k];

			if (!visited[n_node]) {
				visited[n_node] = true;
				depth[n_node] = dpth + 1;
				parent[n_node] = node;

				q.emplace(std::make_pair(n_node, depth[n_node]));
			}
		}
	}
}



int main() {
	scanf("%d", &N);
	connected.assign(N + 1, std::vector<int>());
	depth.assign(N + 1, 0);
	parent.assign(N + 1, 0);
	visited.assign(N + 1, 0);

	for (int k = 0; k < N - 1; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		connected[a].emplace_back(b);
		connected[b].emplace_back(a);
	}

	bfs();
	init();

	scanf("%d", &M);
	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}

}
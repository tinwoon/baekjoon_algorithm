#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>

//11438 LCA2 ����
//�ּ� ���� ������ ����ȭ ������ Sparse Table(��� �迭)�̶� ������ �ʿ���
//�÷� 3�̻��� �Ǿ�� �ȴ� �����ϴ� ����
//��� �迭�̶� Segment Tree�� ����ϰ� 1,2,4,8,16....���� ���� ������� N���� ���� ã�� ���� �迭�� �ǹ��Ѵ�.
//ex) Ư�� �׷������� n�� ���κ��� 15��° ������ ���� ���� ��带 �˰�ʹٸ�
//15���� dfs�� bfs�� 15�� Ž���� ���� ������,
//������ N�� ���� ���� 1��, 2��, 4��, 8���� ������ ���� ��带 ������ �迭(��� �迭)�� ������ �ִٸ�
//8�� ���� ��� -> 4�� ���� ��� -> 2�� ���� ��� -> 1�� ���� ��� == 15�� ���� ���
//�̷� ������ 15�� ���� ��带 4���� ���길���� ���� �� �ִ�.
//�� ������ ��쵵 LCA�� ã�� ���� Level�� �ø��� ������ �� level�� �ø��� ã�� ����� ������,(�� ��� �ð��ʰ�)
//�ѹ��� log(N)level �� �ø��鼭 ã�� ����� ���� ����ȭ�� �����ϴ�.
int N, M, lg, max_depth;

std::vector< std::vector<int> > connected;
std::vector<int> depth;
std::vector<int> parent;
std::vector<bool> visited;
//i�� ��忡 2^j�� ������ �����ΰ�.
std::vector< std::vector<int> > p;

void init() {
	//��� �� ���� ���̰� ���� ����� level = max_depth
	max_depth = *std::max_element(depth.begin(), depth.end());
	//lg = log2(���� ���̰� ���� depth)
	for (lg = 1; (1 << lg) <= max_depth; lg++);
	p.assign(N + 1, std::vector<int>(lg, 0));

	//�� ó�� ��ĭ ����(2^0 == 1)�� parent ���� �ʱ�ȭ
	for (int k = 1; k <= N; k++) {
		p[k][0] = parent[k];
	}

	//parent���� ���� �ʱ�ȭ �� �ϱ�� ����(ex : 4��° ���� ������ ã�� ����� 2��° ���� ������ 2��° ���� ������ ã���� �ȴ�.)
	for (int j = 1; j < lg; j++) {
		for (int i = 1; i <= N; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);

	//���� ���̱��� �÷���.
	for (int k = lg - 1; k >= 0; k--) {
		//2^k��° ������ 0�� �ƴҶ�(Root ��庸�� ���� �ƴ� ��)
		if (p[a][k] && (depth[p[a][k]] >= depth[b])) a = p[a][k];
	}

	//���� ���̱��� �ø� ��尡 ���� ���� ��ġ�Ѵٸ�(b�� a�� �ڽĳ�忴�, �ٷ� �÷ȴ��� ��ġ�߾��ٸ�)
	if (a == b) return a;

	for (int k = lg - 1; k >= 0; k--) {
		//2^k��° ������ Root��庸�� ���� �ƴϰ�(�����ϰ�), 2^k��° ������ ���� �ʴٸ�
		//���Ƶ� �ø��� �ʴ� ������ 1 -> 2 -> 3, 1 -> 2 -> 4�� �� Ʈ���� �ִٰ� �������� ��,
		//3�� 2^1��° ������ => 1, 4�� 2^1��° ������ => 1 �̹Ƿ� ���� ����� �����̳� "�ּ�"���� ������ �ƴ� ���̽��� �����Ѵ�.(�ּ� ���������� ���⼭ 2��)
		//���� ���������� �ƴ� �������� �ִ��� �÷��ָ� �ٷ� �� ���� ���� �������� �ڸ������� ��ġ���� ���� �� ������ �÷��ش�.
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
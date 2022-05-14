#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>

//1854 k��° �ִܰ�� ã�� ����
//���ͽ�Ʈ�� �Ϻ��ϰ� �����ߴ��Ĵ� ���� Ȯ���� �� �ִ� ����
//auto front = pq.top()�� �ؼ� ���� front.first�� node�� �̹� �ִ� ������� �˰��ִ³İ� �߿��ϴ�
//���ͽ�Ʈ���� ��� �ѹ� pop�� ���� ��������� �ش� node������ �ִܰ�ΰ� �̹� Ȯ�ǽ� �Ǿ����� �ƴ����� ���� �����̴�.
//���� pq�� ���� �ڿ� ���µ����� �ִܰ�δ� �ƴ����� ��ó�� ������ �� ���� Ȯ���ϰ� �ִ� ������� �ƴ��� ���� ���̴�.
//��, �������� n�� ��尡 �����ٰ� pq.pop()�� ���� front.first�� n����尡 ó������ ���Դ� => n�� ����� �ִܰ�δ� �̹� Ȯ���ϰ� front.second�̴�.
//�� �Ŀ� ������ n�� ���� �ִ� ��ΰ� �ƴϴ�. 
//�����ϸ� weight[n]�� ������ ��Ȳ���� pq���� n�� ��尡 ���Դ� => �ش� n�� cost���� Ȯ���ϰ� �ִܰ���̴�. 

int N, M, K;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector< std::priority_queue<int> > weight;

void calculate() {
	//cost, node
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	pq.emplace(std::make_pair(0,1));
	weight[1].emplace(0);

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();
		int cost = front.first;
		int node = front.second;

		for (int k = 0; k < connected[node].size(); k++) {
			int ncost = cost + connected[node][k].second;
			int nnode = connected[node][k].first;

			if (weight[nnode].size() == K && weight[nnode].top() > ncost) {
				weight[nnode].pop();
				weight[nnode].emplace(ncost);
				pq.emplace(std::make_pair(ncost, nnode));
			}
			else if(weight[nnode].size() < K){
				weight[nnode].emplace(ncost);
				pq.emplace(std::make_pair(ncost, nnode));
			}

		}
	}

	for (int k = 1; k <= N; k++) {
		if (weight[k].size() == K) printf("%d\n", weight[k].top());
		else printf("-1\n");
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	connected.assign(N + 1, std::vector< std::pair<int, int> >());
	weight.assign(N + 1, std::priority_queue<int>());

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}
	calculate();
}

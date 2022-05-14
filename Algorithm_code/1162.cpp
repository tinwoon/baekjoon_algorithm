#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <limits.h>

//1854 �������� ����
//���ͽ�Ʈ�� + �迭 ���� �ϳ� �� �ø��� ������� Ǯ��
//bfs���� ������ ���ձ⹮���� ���� ���� ���� ������ ������� visited�� ��ĭ �� �ø� ����� �־���.
//���������� �ϵ� ���ͽ�Ʈ��� �����ϸ� �ȴ�.

long long N, M, K;
//2�������� ����
//weight[n�� ���][�������� ������ ������ ����]
std::vector< std::vector<long long> > weight;
std::vector< std::vector< std::pair<long long, long long> > > connected;

long long calculate() {
	//cost, node, pass_road�� ����
	std::priority_queue < std::tuple<long long, long long, long long>, std::vector< std::tuple<long long, long long, long long> >, std::greater< std::tuple<long long, long long, long long> > >pq;
	pq.emplace(std::make_tuple(0, 1, 0));
	weight[1][0] = 0;

	while (!pq.empty()) {
		long long cost, node, pass_road;
		std::tie(cost, node, pass_road) = pq.top();
		pq.pop();

		if (weight[node][pass_road] < cost) continue;

		for (int k = 0; k < connected[node].size(); k++)
		{
			long long n_cost = connected[node][k].second;
			long long n_node = connected[node][k].first;

			if (weight[n_node][pass_road] > weight[node][pass_road] + n_cost) {
				weight[n_node][pass_road] = weight[node][pass_road] + n_cost;
				pq.emplace(std::make_tuple(weight[n_node][pass_road], n_node, pass_road));
			}
			if (pass_road + 1 <= K) {
				if (weight[n_node][pass_road + 1] > weight[node][pass_road]) {
					weight[n_node][pass_road + 1] = weight[node][pass_road];
					pq.emplace(std::make_tuple(weight[n_node][pass_road + 1], n_node, pass_road + 1));
				}
			}

		}
	}

	return *std::min_element(weight[N].begin(), weight[N].end());
}

int main() {
	scanf("%lld %lld %lld", &N, &M, &K);
	weight.assign(N + 1, std::vector<long long>(K + 1, LLONG_MAX));
	connected.assign(N + 1, std::vector< std::pair<long long, long long> >());

	for (int k = 0; k < M; k++) {
		long long a, b, cost;
		scanf("%lld %lld %lld", &a, &b, &cost);
		connected[a].emplace_back(std::make_pair(b, cost));
		connected[b].emplace_back(std::make_pair(a, cost));
	}

	printf("%lld", calculate());
}
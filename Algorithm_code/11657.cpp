#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

//���� ���� �˰��� ����
//���ͽ�Ʈ���� ��� ����� ����ġ���� ������ �� ������
//���������� ��� ������ ����ġ�� cycle�� ���� �����Ͽ� �ִ� ��θ� ã�� �� �ִ�.
//��ü ��尡 5�� �ִٸ� ���� �� �׷����� 4�� �� ���̴�. ��, 5��° �ִ� ��θ� ������ �õ��Ҷ� 5�� �̻��� ���ŵȴٴ� ���� cycle�� �������� �ǹ��Ѵ�.
//���� weight�� ���� ������ ���ͽ�Ʈ��ó�� ���ϸ� �湮�ϵ� ����� ��� ��带 ���Ѵ�(priority queue����� �ʿ� ����)
//�̶� N��° cycle�ÿ����� ���� weigt�� ���ŵȴٴ°� cycle�� �ǹ������� �ش� ������ ������ �۰� �湮�� �� �ֱ⿡ �ִܰ�ΰ� ���� ����̴�. 

int N, M;
std::vector< std::vector< std::pair<int, int> >  > connected;
std::vector<long long> weight;

void calculate(int start) {
	weight[start] = 0;
	bool cycle = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < connected[j].size(); k++) {
				if (weight[j] != LLONG_MAX && weight[connected[j][k].first] > connected[j][k].second + weight[j]) {
					weight[connected[j][k].first] = connected[j][k].second + weight[j];
					if (i == N) cycle = true;
				}
			}
		}
	}

	if (cycle) printf("-1\n");
	else {
		for (int k = 2; k < weight.size(); k++) {
			if (weight[k] != LLONG_MAX) printf("%lld\n", weight[k]);
			else printf("-1\n");
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	connected.assign(N + 1, std::vector< std::pair<int, int> >(0, std::pair<int, int>(0, 0)));
	weight.assign(N + 1, LLONG_MAX);
	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}
	calculate(1);
}

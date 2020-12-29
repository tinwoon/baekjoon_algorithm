#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
std::vector<int> cost;
std::vector<int> weight;
std::vector<int> dp;
//���԰� i�� ���� �� item
std::vector< std::vector<int> > push_item;

//3�г⶧ ���Ѱ� ������ ���ϳ�
// j�� K���� �����ϸ� �̹� ���� ��ǰ�� �ٽ� ���� ���� ������ �� ����.

int calculate() {
	
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 1; j--) {
			if (j - weight[i] >= 0) {
				dp[j] = std::max(dp[j], dp[j - weight[i]] + cost[i]);
			}
		}
	}

	return dp[K];
}


int main() {
	scanf("%d %d", &N, &K);
	dp.assign(K + 1, 0);
	push_item.assign(K + 1, std::vector<int>(0, 0));
	for (int i = 0; i < N; i++) {
		int w, v;
		scanf("%d %d", &w, &v);
		weight.push_back(w);
		cost.push_back(v);
	}
	printf("%d", calculate());
}

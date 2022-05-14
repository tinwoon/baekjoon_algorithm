#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//�������� �÷��̵� ���� �˰����̴�.
//�÷��̵� ������ ���ͽ�Ʈ��, ��������� �� �ٸ� Ư¡�� �ִٸ�
//�ٷ� ���� ��忡�� �ٽ� ���� ���� ���� ���������� �ִ� ��θ� ���� �� �ִٴ� ���̴�.
//�÷��̵� ���ȿ��� dp[i][i]�� ���� 0�� �ƴ� INT_MAX�� �����ϸ� �ִ� ��θ� ���� �� �ִ�. 

int V, E;
std::vector< std::vector<int> > connected;

int floyd() {
	int ans = INT_MAX;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (connected[j][i] != INT_MAX && connected[i][k] != INT_MAX) {
					connected[j][k] = std::min(connected[j][i] + connected[i][k], connected[j][k]);
				}
			}
		}
	}
	for (int k = 1; k <= V; k++) {
		ans = std::min(ans, connected[k][k]);
	}
	return ans != INT_MAX ? ans : -1;
}

int main() {
	scanf("%d %d", &V, &E);
	connected.assign(V + 1, std::vector<int>(V+1, INT_MAX));
	for (int k = 0; k < E; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a][b] = c;
	}
	printf("%d", floyd());
}

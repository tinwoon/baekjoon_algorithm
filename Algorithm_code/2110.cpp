#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//������ ��ġ ����
//��Ÿ������ ����� ������ ���� �Ķ��Ʈ�� ��ġ�� ��ư� �����ȴٸ� �̷��� �� ���̴�.
//��ġ ������ ���Ƿ� �ľ��Ͽ� �� �̻����� �ƴ����� �̺�Ž���� �����Ѵ�.

int N, C;
std::vector<int> ip;

int calculate() {
	int begin = 0;
	int end = ip[N - 1] - ip[0];
	int ans = INT_MIN;

	while (begin <= end) {
		int set_ip = 1;
		int p_node = 0;
		//������ ��ġ�ϴµ� ������ �Ÿ�
		int mid = (begin + end) / 2;

		for (int k = 1; k < N; k++) {
			if (ip[k] - ip[p_node] >= mid) {
				set_ip++;
				p_node = k;
			}
		}

		if (set_ip >= C) {
			ans = std::max(ans, mid);
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &C);
	ip.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &ip[k]);
	}
	std::sort(ip.begin(), ip.end());
	printf("%d", calculate());
}
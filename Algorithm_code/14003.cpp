#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

//14003 ���� �� �����ϴ� �κ� ���� 5
//������ �߿��ϴ�. �� �ش�˰����� ����Ұ�
//lis ������ ���� ȿ������ �˰�������
//k��°�� data�� �ش��ϴ� ���� lis �迭���� ���° �ε����� �ش��ϴ����� ���´�.
//���� ��� 10 20 10 30 20 50�� ���
//index �迭���� 1 2 1 3 2 4 ������ ����ȴ�.
//���� lis�� index�� �ݴ� �������� 4,3,2,1�� �ش��ϴ� ���� 50 30 20 10�� �������� �����ϸ� �ȴ�.
//�� �������� �ϰ� ����ϳİ� ������ �� �ִµ�
//-2 3 5 1 2 3 4�� index�� ��� 1 2 3 1 2 3 4�� ���� -2 3 5 4��� �ùٸ��� ���� ����� �����ȴ�.
//���� �ڿ������� ã�� �������� �ٲ� ����ؾ��Ѵ�.
long long N;
std::vector<long long> data;
std::vector<long long> lis;
std::vector<long long> index;
std::stack<long long> ans;

long long count = 0;

long long calculate() {
	lis.emplace_back(LLONG_MIN);

	for (int k = 0; k < N; k++) {
		if (lis.back() < data[k]) {
			count++;
			lis.emplace_back(data[k]);
			index[k] = (long long)lis.size() - 1;
		}
		else {
			auto itr = std::lower_bound(lis.begin(), lis.end(), data[k]);
			index[k] = (long long)std::distance(lis.begin(), itr);
			*itr = data[k];
		}
	}

	return count;
}

int main() {
	scanf("%lld", &N);
	data.assign(N, 0);
	index.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &data[k]);
	}
	printf("%lld\n", calculate());

	int r_index = count;
	for (int k = N - 1; k >= 0; k--) {
		if (index[k] == r_index) {
			ans.emplace(data[k]);
			r_index--;
		}
	}

	while (!ans.empty()) {
		printf("%lld ", ans.top());
		ans.pop();
	}
}
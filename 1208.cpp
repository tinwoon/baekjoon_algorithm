#include <iostream>
#include <vector>
#include <algorithm>


int N, S;
std::vector<int> value;
long long rst = 0;


//��¥ ������� 
//��Ʈ �����ڸ� ���� ����
//�κ� ������ ���� �ΰ��� ����
//���� ��� value�� ���� 12345��
// first_subset���� 12�� ���� �κм����� ��
// second_subset���� 345�� ���� �κм����� ���� ���Ѵ�
// �׷��� ���� first_subset�� second_subset�� �κ� ������ ������ �� �κм����� ���� ���ϸ� �ȴ�.

//�ڲ� Ʋ�� ������ �ִµ� con_first�� con_second�� ���� long long���� ���ϰ� int�� ��
//first_subset�� second_subset�� ���� ��� ���� ���� ���� S�� ���ٸ�
//�ִ� (1<<20)*(1<<20)���� �� �� �ִٴ� ���� ������.

long long calculate() {
	int first = N / 2;
	int second = N - first;
	//subset���� �κ����յ��� ���� ��� ������.
	std::vector<int> subset;
	std::vector<int> first_subset;
	std::vector<int> second_subset;


	int cur = 0;
	for (int i = 0; i < (1 << first); i++) {
		for (int j = 0; j < first; j++) {
			if (i & (1 << j)) {
				cur += value[j];
			}
		}
		first_subset.push_back(cur);
		cur = 0;
	}
	for (int i = 0; i < (1 << second); i++) {
		for (int j = 0; j < second; j++) {
			if (i & (1 << j)) {
				cur += value[j + first];
			}
		}
		second_subset.push_back(cur);
		cur = 0;
	}
	sort(first_subset.begin(), first_subset.end());
	sort(second_subset.begin(), second_subset.end());
	std::reverse(second_subset.begin(), second_subset.end());

	int first_stack = 0;
	int second_stack = 0;

	while (1) {
		if (first_stack == first_subset.size() || second_stack == second_subset.size()) break;


		if (first_subset[first_stack] + second_subset[second_stack] == S) {
			long long con_first = 1;
			long long con_second = 1;
			while (first_stack + 1 < first_subset.size()) {
				if (first_subset[first_stack] == first_subset[first_stack + 1]) {
					con_first++;
					first_stack++;
				}
				else break;
			}
			while (second_stack + 1 < second_subset.size()) {
				if (second_subset[second_stack] == second_subset[second_stack + 1]) {
					con_second++;
					second_stack++;
				}
				else break;
			}


			rst += con_first * con_second;
			first_stack++;
			second_stack++;
		}
		else if (first_subset[first_stack] + second_subset[second_stack] < S) {
			first_stack++;
		}
		else {
			second_stack++;
		}
	}

	if (S == 0) rst -= 1;
	return rst;


}

int main() {
	scanf("%d %d", &N, &S);
	value.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &value[i]);
	}
	printf("%lli", calculate());
}

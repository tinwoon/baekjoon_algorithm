#include <iostream>
#include <vector>
#include <algorithm>

//���� 0 ����
//�ش� ������ �ܼ��� �����ó�� �̺�Ž���� ���� Ǯ �� �ִ� �����̴�.
//�ΰ��� �л��� ������ ã�Ƽ� ������ �� �ش� ���� ���� �л��� ���� ����� ���� ��� �����ָ� �Ǵ� �����̴�. 

int N;
std::vector<int> student;

long long calculate() {
	long long count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int two_sum = student[i] + student[j];
			auto same_another = std::equal_range(student.begin() + (j + 1), student.end(), two_sum * -1);
			count += (long long)(same_another.second - same_another.first);
		}
	}
	return count;
}

int main() {
	scanf("%d", &N);
	student.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &student[k]);
	}
	std::sort(student.begin(), student.end());
	printf("%lld", calculate());
}

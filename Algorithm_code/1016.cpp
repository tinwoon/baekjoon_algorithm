#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <math.h>

//min, max �� ������ 1000,000 �ΰ� ����(max ���� 1000,000,000,000 �̿��� visited Ȱ�� ���ϴ� �� �˾���) 
//visited �Ҵ��� ���ϰ� ����ȭ ��ų ����� ������ ���� �ɷȴ� ����
//��������� �����佺�׳׽��� ä�� Ȱ���ؼ� Ǯ����, ����Ǵ� ���� Ȯ����.
// find �Լ��� ���� min���� ũ�鼭 ���� k*k�� �ش��ϴ� �� �� ���� ���� ���� return �ϵ��� ������
// ex) min = 102���� k*k�� 4�� ����� �� �� min���� ū �� �߿��� ���� ���� ���� 104�̴�. 

long long min, max;
std::vector<bool> visited;

long long find(long long x) {
	long long cmp = (min / x) * x;
	return (cmp < min) ? (cmp + x) : min;
}

int calculate() {
	int rst = max - min + 1;

	visited.assign(rst, false);

	for (int k = 2; k <= sqrt(max); k++) {
		long long add = (long long)k * k, start = find(k * k);
		do {
			if ((min <= start) && (start <= max) && !visited[start - min]) {
				visited[start - min] = true;
				rst--;
			}
		} while ((start += add) <= max);
	}
	return rst;
}

int main() {
	scanf("%lld %lld", &min, &max);
	printf("%d", calculate());
}

//https://www.acmicpc.net/problem/14225
//�ð��� �ٸ� ������� 4�� ���� �� �ɸ��µ� �ٸ� ����� �迭�� ũ�⸦
//bool c[20*100000+10]������ ó������ ����(���� 10�� Ȥ�� �ʰ��ұ��)
//�迭�� �Ҵ緮�� �޸𸮸� Ȯ���ϰ� Ǯ�� ���� �������� ����� ���°� ���� �� �� ����.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int n;
std::vector<int> digit;

int calculate() {
	std::set<int> make_value;
	for (int i = 1; i < (1<<n); i++) {
		int value = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) value += digit[j];
		}
		make_value.insert(value);
	}

	
	int tmp = 1;
	for (auto itr = make_value.begin(); itr != make_value.end(); itr++) {
		if (*itr != tmp) {	
			return tmp;
		}
		else tmp++;
	}
	return make_value.size() + 1;

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		digit.push_back(tmp);
	}
	printf("%d", calculate());
}


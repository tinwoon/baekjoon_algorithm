#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <string>

//map ���� ����
//������ C���� Ǯ���� ��� �ؾ��ϴ°�
//��� �ʿ�

std::map<std::string, int> S;
std::string data;
int N, M;
int ans;

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 0; k < N; k++) {
		std::cin >> data;
		S.insert(std::make_pair(data, 1));
	}
	for (int k = 0; k < M; k++) {
		std::cin >> data;
		if (S.count(data)) ans++;
	}
	printf("%d", ans);
}
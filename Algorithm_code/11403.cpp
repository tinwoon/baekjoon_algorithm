#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//11403�� ��� ã�� ����
//�÷��̵� �ͼ� ������ ����� ������ ����.

int N;
std::vector< std::vector <int> > data;

void calculate() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (data[i][k] && data[k][j]) data[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d", &N);
	data.assign(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &data[i][j]);
		}
	}
	calculate();
}
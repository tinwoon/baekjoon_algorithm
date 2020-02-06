#include <iostream>
#include <stdlib.h>

using namespace std;


//2���� �迭 �Ű������� ������ ������ ù��°�� ���� �ι�°�� ������ ���� ����Ͽ��� �Ѵ�.
//bottom up���� �ذ�

void value(int data[500][500], int n, int m) {
	data[n][m] += data[n + 1][m] > data[n + 1][m + 1] ? data[n + 1][m] : data[n + 1][m + 1];
}


int main() {
	int num = 0;
	int data[500][500] = { 0, };
	int stack = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	for (int i = num - 2; i >= 0; i--) {
		for (int j = 0; j < i + 1; j++) {
			value(data, i, j);
		}
	}

	printf("%d", data[0][0]);


}


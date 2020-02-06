#include <iostream>
#include <stdlib.h>

using namespace std;



void calculate(int n, int** data) {

	if (n == 0) {
		data[0][0] = 1;
	}
	else if (n == 1) {
		data[1][1] = 1;
	}
	else {
		data[n][0] = data[n - 1][0] + data[n - 2][0];
		data[n][1] = data[n - 1][1] + data[n - 2][1];
	}
}

int main() {

	int num = 0;
	int stack = 0;
	int max = 0;
	scanf("%d", &num);
	//num������ �ԷµǴ� ���� ���� (ex 0 1 3) 
	int* scan_value = (int*)malloc(sizeof(int)*num);

	//0��1�� ������������� �����ϴ� ������ �迭 
	

	//for���� ���鼭 ���� �����ϰ� ���� ���� ���� ã��
	//(max�������� �Ǻ���ġ �ϸ� �Ǳ⶧����) 
	for (int i = 0; i < num; i++) {
		scanf("%d", &scan_value[i]);
		if (max < scan_value[i]) max = scan_value[i];
	}

	int** data = (int**)malloc(sizeof(int*)*(max + 1));
	for (int i = 0; i < max + 1; i++) {
		data[i] = (int*)malloc(sizeof(int) * 2);
	}

	//data�� �ʱ� ȭ 
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < 2; j++) {
			data[i][j] = 0;
		}
	}

	//max���� ���� dp�� ��� ���� �� �� 
	//0���� max������ ���� ����ϱ� ���� 
	for (int i = 0; i <max+1; i++) {
		calculate(i, data);

		//���� ������ �Է��� ���̶� ��ġ�Ѵٸ� ���� ����ϱ� 
		if (i == scan_value[stack]) {
			printf("%d %d\n", data[i][0], data[i][1]);
			stack++;
		}

	}
	
		for (int i = 0; i <max+1; i++) {
		//���� ������ �Է��� ���̶� ��ġ�Ѵٸ� ���� ����ϱ� 
		if (i == scan_value[stack]) {
			printf("%d %d\n", data[i][0], data[i][1]);
			stack++;
		}

	}


	free(data);
	free(scan_value);
	return 0;
}


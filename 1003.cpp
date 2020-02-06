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
	//num다음에 입력되는 값을 저장 (ex 0 1 3) 
	int* scan_value = (int*)malloc(sizeof(int)*num);

	//0과1이 몇번나오는지를 저장하는 이차원 배열 
	

	//for문을 돌면서 값을 저장하고 가장 높은 값을 찾음
	//(max값까지만 피보나치 하면 되기때문에) 
	for (int i = 0; i < num; i++) {
		scanf("%d", &scan_value[i]);
		if (max < scan_value[i]) max = scan_value[i];
	}

	int** data = (int**)malloc(sizeof(int*)*(max + 1));
	for (int i = 0; i < max + 1; i++) {
		data[i] = (int*)malloc(sizeof(int) * 2);
	}

	//data값 초기 화 
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < 2; j++) {
			data[i][j] = 0;
		}
	}

	//max까지 값을 dp로 얻기 위해 계 산 
	//0부터 max까지의 값을 계산하기 위해 
	for (int i = 0; i <max+1; i++) {
		calculate(i, data);

		//만약 이전에 입력한 값이랑 일치한다면 값을 출력하기 
		if (i == scan_value[stack]) {
			printf("%d %d\n", data[i][0], data[i][1]);
			stack++;
		}

	}
	
		for (int i = 0; i <max+1; i++) {
		//만약 이전에 입력한 값이랑 일치한다면 값을 출력하기 
		if (i == scan_value[stack]) {
			printf("%d %d\n", data[i][0], data[i][1]);
			stack++;
		}

	}


	free(data);
	free(scan_value);
	return 0;
}


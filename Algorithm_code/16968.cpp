#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//16968 ������ȣ�� 1�� ����
//�ܼ� ����� �� ������ ����� �κ��� ������. 

char input[5];
int c_size = 26;
int d_size = 10;

int calculate(char*);

int main() {
	scanf("%s", input);
	printf("%d", calculate(input));
}

int calculate(char* input) {
	int ans = 1;
	int size = strlen(input);
	for (int k = 0; k < size; k++) {
		if (input[k] == 'c') {
			if (k != 0 && input[k - 1] == 'c') ans *= 25;
			else ans *= 26;
		}else if (input[k] == 'd') {
			if (k != 0 && input[k - 1] == 'd') ans *= 9;
			else ans *= 10;
		}
	}
	return ans;
}

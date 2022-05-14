#include <iostream>
#include <vector>
#include <math.h>


//�� �̾��1
//1~9 ������ 9*1
//10~99 ������ 90*2
//100~999 ������ 900*3�� ������ ������ �̿�
std::vector<int> digit_value(9);




int how_digit(int num) {
	int stack = 0;
	while (num != 0) {
		num /= 10;
		stack++;
	}
	return stack;
}

int main() {
	int num = 0;
	int result = 0;
	int stack = 0;
	scanf("%d", &num);
	for (int i = 0; i < how_digit(num) - 1; i++) {
		result += (i + 1) * 9 * pow(10, i);
	}
	result += (num - pow(10, how_digit(num) - 1) + 1) * how_digit(num);
	printf("%d\n", result);
}
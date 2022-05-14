#include <iostream>
#include <vector>
#include <math.h>


//수 이어쓰기1
//1~9 까지는 9*1
//10~99 까지는 90*2
//100~999 까지는 900*3을 가지는 원리를 이용
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
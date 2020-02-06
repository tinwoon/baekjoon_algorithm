#include <stdio.h>

//소수점 9번째 자리까지 출력하는거에 대한 공부필요 
int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.9lf\n", a / b);
	return 0;
}


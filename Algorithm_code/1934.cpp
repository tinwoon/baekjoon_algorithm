#include <iostream>
#include <math.h>
#include <algorithm>

//최대 공배수 문제
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a,int b) {
	return a * b / gcd(a, b);
}

int main() {
	int a, b;
	int num = 0;
	scanf("%d", &num); 
	while (num--) {
		scanf("%d %d", &a, &b);
		if (a < b) {
			std::swap(a, b);
		}
		printf("%d\n", lcm(a, b));
	}
	
	return 0;
}

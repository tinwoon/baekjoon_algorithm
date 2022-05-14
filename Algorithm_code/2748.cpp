#include <iostream>
#include <stdlib.h>

using namespace std;


//핵심은 dp와 long long 형의 자료구조가 핵 심 
void calculate(int n, long long* data) {

	if (n == 0) {
		data[0] = 0;
	}
	else if (n == 1) {
		data[1] = 1;
	}
	else {
		long long a = data[n - 1] + data[n - 2];
		data[n] = a;
	}
}

int main() {
	long long data[91] = {0, };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n+1; i++) {
		calculate(i, data);
	}
	printf("%lld", data[n]);


}


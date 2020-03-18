#include<iostream>

long long data[1500050];

//백준 2749 피보나치 문제
//피사노 주기라는 사기적인 알고리즘에 대해 알아야만 풀 수 있는 문제
//알고리즘은 고민하지말고 답지 보세용
void fibonacci() {
	data[0] = 0;
	data[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		data[i + 2] = (data[i + 1] + data[i]) % 1000000;
	}
}

int main() {
	long long n;
	scanf("%lli", &n);
	fibonacci();
	printf("%d\n",data[n % 1500000]);

}


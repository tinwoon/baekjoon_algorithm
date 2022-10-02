#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <math.h>

//min, max 간 조건이 1000,000 인걸 몰라서(max 값이 1000,000,000,000 이여서 visited 활용 못하는 줄 알았음) 
//visited 할당을 못하고 최적화 시킬 방법을 생각해 오래 걸렸던 문제
//결론적으로 에라토스테네스의 채를 활용해서 풀었고, 통과되는 내역 확인함.
// find 함수를 통해 min보다 크면서 가장 k*k에 해당하는 값 중 가장 작은 값을 return 하도록 유도함
// ex) min = 102에서 k*k인 4의 배수의 값 중 min보다 큰 값 중에서 제일 작은 값은 104이다. 

long long min, max;
std::vector<bool> visited;

long long find(long long x) {
	long long cmp = (min / x) * x;
	return (cmp < min) ? (cmp + x) : min;
}

int calculate() {
	int rst = max - min + 1;

	visited.assign(rst, false);

	for (int k = 2; k <= sqrt(max); k++) {
		long long add = (long long)k * k, start = find(k * k);
		do {
			if ((min <= start) && (start <= max) && !visited[start - min]) {
				visited[start - min] = true;
				rst--;
			}
		} while ((start += add) <= max);
	}
	return rst;
}

int main() {
	scanf("%lld %lld", &min, &max);
	printf("%d", calculate());
}

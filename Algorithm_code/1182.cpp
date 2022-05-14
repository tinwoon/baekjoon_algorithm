#include <iostream>
#include <vector>

int N, S;
std::vector<int> value;
int cnt;

//비트마스크 이용

void calculate() {
	for (int i = 1; i < (1 << N); i++) {
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				sum += value[j];
			}
		}
		if (sum == S) cnt++;
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		value.push_back(tmp);
	}
	calculate();
	printf("%d", cnt);
}

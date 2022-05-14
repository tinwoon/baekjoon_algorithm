#include <iostream>
#include <vector>

int E, S, M;
//브루트포스

int main() {
	scanf("%d %d %d", &E, &S, &M);
	for (int i = 1; i <= 2000000000; i++) {
		int e, s, m;
		e = i % 15 == 0 ? 15 : i % 15;
		s = i % 28 == 0 ? 28 : i % 28;
		m = i % 19 == 0 ? 19 : i % 19;
		if ((e == E) && (s == S) && (m == M)) {
			printf("%d", i);
			return 0;
		}
	}
}

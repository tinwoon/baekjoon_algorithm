#include <iostream>
#include <vector>

int N, M, H;
std::vector< std::vector<bool> > ladder;

int calculate() {

}

int main() {
	scanf("%d %d %d", &N, &M, &H);
	ladder.assign(M, std::vector<bool>(N, 0));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ladder[a][b] = true;
	}

}

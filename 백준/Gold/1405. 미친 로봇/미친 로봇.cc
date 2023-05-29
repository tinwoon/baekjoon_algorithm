#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <float.h>

int N;
double ans;
std::vector< std::vector<bool> > visited;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
double possible[4];

void calculate(int x, int y, double v) {
	if (N == 0) {
		ans += v;
		return;
	}
	visited[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (!visited[nx][ny]) {
			N--;
			calculate(nx, ny, v * possible[k]);
			N++;
			visited[nx][ny] = false;
		}
	}
}

int main() {
	scanf("%d %lf %lf %lf %lf", &N,
		&possible[0], &possible[1], &possible[2], &possible[3]);
	for (int k = 0; k < 4; k++) {
		possible[k] *= 0.01;
	}
	visited.assign((2 * N) + 1, std::vector<bool>((2 * N) + 1, false));
	calculate(N, N, 1.0);
	printf("%.11g", ans);
}
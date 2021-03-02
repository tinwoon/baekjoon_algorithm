#include <iostream>
#include <vector>

int N, K;
//길이 x에 k값
bool visited[31][31][31][436];
std::string ans;
bool flag = false;

//k_value엔 만족하는 쌍 k개
void calculate(std::string rst, int k_value, int a_size, int b_size) {
	if (rst.size() == N) {
		if (k_value == K) {
			std::cout << rst;
			exit(0);
		}
	} 
	else {
		int c_size = rst.size() - a_size - b_size;
		if (!visited[a_size + 1][b_size][c_size][k_value]) {
			visited[a_size + 1][b_size][c_size][k_value] = true;
			calculate(rst + 'A', k_value, a_size + 1, b_size);
		}

		if (!visited[a_size][b_size + 1][c_size][k_value + a_size]) {
			visited[a_size][b_size + 1][c_size][k_value + a_size] = true;
			calculate(rst + 'B', k_value + a_size, a_size, b_size + 1);
		}

		if (!visited[a_size][b_size][c_size + 1][k_value + a_size + b_size]) {
			visited[a_size][b_size][c_size + 1][k_value + a_size + b_size] = true;
			calculate(rst + 'C', k_value + a_size + b_size, a_size, b_size);
		}
	}
	
}

int main() {
	scanf("%d %d", &N, &K);

	
	calculate("", 0, 0, 0);
	printf("-1");
}

#include <iostream>
#include <vector>
#include <deque>
#include <math.h>

//화딱지나서 그냥 경우의 수 다함.

std::vector< std::deque<int> > dq;
int k;
int rst = 0;

void rotate(int value, int degree) {
	if (degree == 1) {
		int tmp = dq[value].back();
		dq[value].push_front(tmp);
		dq[value].pop_back();
	}
	else {
		int tmp = dq[value].front();
		dq[value].push_back(tmp);
		dq[value].pop_front();
	}
}

void calculate(int number, int degree) {
	std::vector<bool> is_ok(5, false);
	std::vector<int> is_degree(5, 0);
	is_ok[number] = true;
	is_degree[number] = degree;
	switch (number) {
		case 1:
			if (dq[1][2] != dq[2][6]) {
				is_ok[2] = true;
				is_degree[2] = degree * -1;
				if (dq[2][2] != dq[3][6]) {
					is_ok[3] = true;
					is_degree[3] = degree;
					if (dq[3][2] != dq[4][6]) {
						is_ok[4] = true;
						is_degree[4] = degree * -1;
					}
				}
			}
			break;
		case 2:
			if (dq[2][6] != dq[1][2]) {
				is_ok[1] = true;
				is_degree[1] = degree * -1;
			}
			if (dq[2][2] != dq[3][6]) {
				is_ok[3] = true;
				is_degree[3] = degree * -1;
				if (dq[3][2] != dq[4][6]) {
					is_ok[4] = true;
					is_degree[4] = degree;
				}
			}
			break;
		case 3:
			if (dq[3][2] != dq[4][6]) {
				is_ok[4] = true;
				is_degree[4] = degree * -1;
			}
			if (dq[3][6] != dq[2][2]) {
				is_ok[2] = true;
				is_degree[2] = degree * -1;
				if (dq[2][6] != dq[1][2]) {
					is_ok[1] = true;
					is_degree[1] = degree;
				}
			}
			break;
		case 4:
			if (dq[4][6] != dq[3][2]) {
				is_ok[3] = true;
				is_degree[3] = degree * -1;
				if (dq[3][6] != dq[2][2]) {
					is_ok[2] = true;
					is_degree[2] = degree;
					if (dq[2][6] != dq[1][2]) {
						is_ok[1] = true;
						is_degree[1] = degree * -1;
					}
				}
			}
			break;
	}

	for (int i = 1; i <= 4; i++) {
		if (is_ok[i] == true) {
			rotate(i, is_degree[i]);
		}
	}
	
}
	

int main() {

	dq.assign(6, std::deque<int>(8, 0));
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &dq[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		calculate(a,b);
	}
	for (int i = 1; i <= 4; i++) {
		rst += dq[i][0] * pow(2, i-1);
	}
	printf("%d", rst);
}

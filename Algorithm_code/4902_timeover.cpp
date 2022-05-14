#include <iostream>
#include <vector>
#include <math.h>

std::vector< std::vector<int> > triangle;
std::vector< std::vector<bool> > triangle_ok;



int calculate(int tmp) {
	int rst = 0;
	for (int i = 0; i < tmp; i++) {
		for (int j = tmp - 1 - i; j <= tmp - 1 + i; j++) {
			//정삼각형 모양일 때
			if (triangle_ok[i][j]) {
				bool flag = true;
				int data = 0;
				for (int a = i; a < tmp; a++) {
					if (!flag) break;
					for (int b = j - (a - i); b <= j + (a - i); b++) {
						if (a >= 0 && a < tmp && b >= tmp - 1 - a && b <= tmp - 1 + a) {
							data += triangle[a][b];
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) rst = rst < data ? data : rst;
				}
			}
			//역 삼각형 모양일때
			else if (!triangle_ok[i][j]) {
				bool flag = true;
				int data = 0;
				for (int a = i; a >=0; a--) {
					if (!flag) break;
					for (int b = j - (i - a); b <= j + (i - a); b++) {
						if (a >= 0 && a < tmp && b >= tmp - 1 - a && b <= tmp - 1 + a) {
							data += triangle[a][b];
						}
						else {
							flag = false;
							break;
						}
					}
					if (flag) rst = rst < data ? data : rst;
				}
			}
		}
	}
	return rst;
}

int main() {
	int stack = 0;
	while (1) {
		stack++;
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) break;
		triangle.assign(tmp, std::vector<int>(2 * tmp - 1, -10000));
		triangle_ok.assign(tmp, std::vector<bool>(2 * tmp - 1, false));

		for (int i = 0; i < tmp; i++) {
			bool is_ok = true;
			for (int j = tmp - 1 - i; j <= tmp - 1 + i; j++) {
				scanf("%d", &triangle[i][j]);
				triangle_ok[i][j] = is_ok;
				is_ok = !is_ok;
			}
		}

		printf("%d. %d\n", stack, calculate(tmp));
	}
}


//2630색종이 문제
//입력
//첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다.N은 2, 4, 8, 16, 32, 64, 128 중 하나이다.색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다.하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.
//
//출력


#include <iostream>
#include <vector>

int map[128][128];
int white = 0;
int blue = 0;


void calculate(int x1, int y1, int x2, int y2) {
	int whilte_count = 0;
	int blue_count = 0;
	for (int i = x1; i < x2+1; i++) {
		for (int j = y1; j < y2+1; j++) {
			if (map[i][j] == 0) {
				whilte_count++;
			}
			else blue_count++;
			
		}
	}

	if (whilte_count==0) {
		blue++;
		return;
	}
	else if (blue_count == 0) {
		white++;
		return;
	}
		calculate(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
		calculate(((x1 + x2) / 2) + 1, y1, x2, (y1 + y2) / 2);
		calculate(x1, ((y1 + y2) / 2) + 1, (x1 + x2) / 2, y2);
		calculate(((x1 + x2) / 2) + 1, ((y1 + y2) / 2) + 1, x2, y2);

	
	
	
}

int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	calculate(0, 0, n-1, n-1);
	printf("%d\n%d", white, blue);



}

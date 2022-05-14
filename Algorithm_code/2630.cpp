
//2630������ ����
//�Է�
//ù° �ٿ��� ��ü ������ �� ���� ���� N�� �־��� �ִ�.N�� 2, 4, 8, 16, 32, 64, 128 �� �ϳ��̴�.�������� �� �������� ���簢��ĭ���� ���� ���ٺ��� ���ʷ� ��° �ٺ��� ������ �ٱ��� �־�����.�Ͼ������ ĥ���� ĭ�� 0, �Ķ������� ĥ���� ĭ�� 1�� �־�����, �� ���� ���̿��� ��ĭ�� �ϳ��� �ִ�.
//
//���


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

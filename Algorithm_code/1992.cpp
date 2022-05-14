
//1992 ����Ʈ�� ����
//�Է�
//ù° �ٿ��� ������ ũ�⸦ ��Ÿ���� ���� N �� �־�����.N �� ������ 2�� �������� �־�����, 1��N ��64�� ������ ������.�� ��° �ٺ��ʹ� ���� N �� ���ڿ��� N �� ���´�.�� ���ڿ��� 0 �Ǵ� 1�� ���ڷ� �̷���� ������, ������ �� ������ ��Ÿ����.
//
//���
//������ ������ ����� ����Ѵ�.
//���� ������ �̿��Ͽ� ǰ.


#include <iostream>
#include <vector>




void calculate(int x1, int y1, int size, std::vector< std::vector<int> > &map) {
	
	int zero_cnt = 0;
	int one_cnt = 0;
	if (size == 1) {
		printf("%d",map[x1][y1]);
	}
	else {
		for (int i = x1; i < x1 + size; i++) {
			for (int j = y1; j < y1 + size; j++) {
				if (map[i][j] == 0) {
					zero_cnt++;
				}
				else one_cnt++;
			}
		}



		if (zero_cnt == 0) {
			printf("1");
		}
		else if (one_cnt == 0) {
			printf("0");
		}
		else {
			printf("(");
			calculate(x1, y1, size / 2, map);
			calculate(x1 + (size / 2), y1, size / 2, map);
			calculate(x1, y1 + (size / 2), size / 2, map);
			calculate(x1 + (size / 2), y1 + (size / 2), size / 2, map);
			printf(")");
		}
	}
		
}

int main() {
	int n = 0;
	std::vector< std::vector<int> >map;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		std::vector<int> tmp(n);
		map.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[j][i]);
		}
	}

	calculate(0, 0, n, map);

}

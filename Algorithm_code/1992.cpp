
//1992 쿼드트리 문제
//입력
//첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다.N 은 언제나 2의 제곱수로 주어지며, 1≤N ≤64의 범위를 가진다.두 번째 줄부터는 길이 N 의 문자열이 N 개 들어온다.각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.
//
//출력
//영상을 압축한 결과를 출력한다.
//분할 정복을 이용하여 품.


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

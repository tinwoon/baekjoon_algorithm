#include <iostream>
#include <vector>


//스도쿠 문제
//이걸 한번에 성공하네 지원이 대단해
//백트래킹을 통해 구현


std::vector< std::vector<int> > sudoku(9, std::vector<int>(9, 0));


int is_block_row(int index) {
	int a = index / 9;
	a /= 3;
	a *= 3;
	return a;
}

int is_block_col(int index) {
	int b = index % 9;
	b /= 3;
	b *= 3;
	return b;
}

//i가 들어갈 수 있나?를 확인
bool discriminate(int i,int index) {
	for (int a = 0; a < 9; a++) {
		if ((sudoku[index / 9][a] == i) || (sudoku[a][index % 9] == i) || (sudoku[is_block_row(index)+a/3][is_block_col(index)+a%3]==i) ) return false;
	}
	return true;
}


void calculate(int index) {
	if (index == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	
	if (sudoku[index / 9][index % 9] == 0) {
		for (int i = 1; i < 10; i++) {
			if (discriminate(i, index)) {
				sudoku[index / 9][index % 9] = i;
				calculate(index + 1);
				sudoku[index / 9][index % 9] = 0;
			}
		}
	}
	else calculate(index + 1);
}



int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sudoku[i][j]);
		}
	}
	calculate(0);
}

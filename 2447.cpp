//지원 코드
//핵심은 분할정복과 재귀적 호 출  
#include <iostream>
#include <vector>

using namespace std;



vector< vector<bool> > v;

void wide_print_star(vector< vector<bool> > &vector, int i, int j, int stack) {
	for (int x = i; x < i + stack; x++) {
		for (int y = j; y < j + stack; y++) {
			vector[x][y] = false;
		}
	}
}


int return_empty(vector< vector<bool> > &vector, int n, int number) {
	int stack = 0;
	stack = n / 3;
	if (stack < 1) {
		return 0;
	}
	else {
		for (int i = stack; i < number; i = i + n) {
			for (int j = stack; j < number; j = j + n) {
				wide_print_star(v, i, j, stack);
			}
		}
		return return_empty(vector, stack, number);
	}
}

void print_star(vector< vector<bool> > &vector) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (vector[i][j] == true) {
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
}




int main() {
	int n = 0;

	scanf_s("%d", &n);
	v.assign(n, vector<bool>(n, true));
	return_empty(v, n, n);
	print_star(v);


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니


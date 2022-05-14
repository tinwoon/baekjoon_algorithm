#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> alphabet;
std::string alphabet_kind;
std::string pass_alphabet;
int max = 0;
int R, C;

//문제로직 자체는 쉬웠지만 전략이 문제였음
//백트래킹을 통해 잘 풀었지만 시간초과가 났었음
//이유는 알파벳의 종류를 모두 탐색했어도 백트래킹으로 다시 되돌아갔기때문
//이때 알파벳의 모든 종류를 담은 alphabet_kind를 통해 해당 size와 같으면
//방문할 수 있는 모든 알파벳을 방문한 것임으로 바로 print하고 종료하면 됨.

//c값을 지나도 되는지 물어보는 코드
bool is_ok_passed(char c) {
	for (int i = 0; i < pass_alphabet.size(); i++) {
		if (pass_alphabet[i] == c) return false;
	}
	return true;
}

//알파벳 종류 알려주는 코드
void alphabet_num() {
	for (int i = 0; i < alphabet.size(); i++) {
		alphabet_kind += alphabet[i];
	}
	sort(alphabet_kind.begin(), alphabet_kind.end());
	alphabet_kind.erase(std::unique(alphabet_kind.begin(), alphabet_kind.end()), alphabet_kind.end());

}

//오른쪽으로 가는게 괜찮은지 알려주는 코드
bool right_is_OK(int row, int col) {

	if (col + 1 < C) {
		if (is_ok_passed(alphabet[row][col + 1])) return true;
	}
	return false;
}

//왼쪽으로 가는게 괜찮은지 알려주는 코드
bool left_is_OK(int row, int col) {
	if (col - 1 >= 0) {
		if (is_ok_passed(alphabet[row][col - 1])) return true;
	}
	return false;
}

//위쪽으로 가는게 괜찮은지 알려주는 코드
bool bottom_is_OK(int row, int col) {
	if (row + 1 < R) {
		if (is_ok_passed(alphabet[row + 1][col])) return true;
	}
	return false;
}

//아래쪽으로 가는게 괜찮은지 알려주는 코드
bool top_is_OK(int row, int col) {
	if (row - 1 >= 0) {
		if (is_ok_passed(alphabet[row - 1][col])) return true;
	}
	return false;
}



void calculate(int row, int col, int stack) {
	if (row == 0 && col == 0) {
		pass_alphabet.push_back(alphabet[row][col]);
		stack++;
	}

	if (right_is_OK(row, col)) {
		pass_alphabet.push_back(alphabet[row][col + 1]);
		calculate(row, col + 1,stack+1);
		pass_alphabet.pop_back();
	}
	if (bottom_is_OK(row, col)) {
		pass_alphabet.push_back(alphabet[row + 1][col]);
		calculate(row + 1, col,stack+1);
		pass_alphabet.pop_back();
	}
	if (left_is_OK(row, col)) {
		pass_alphabet.push_back(alphabet[row][col - 1]);
		calculate(row, col - 1,stack+1);
		pass_alphabet.pop_back();
	}
	if (top_is_OK(row, col)) {
		pass_alphabet.push_back(alphabet[row - 1][col]);
		calculate(row - 1, col,stack+1);
		pass_alphabet.pop_back();
	}
	max = std::max(max, stack);
	//이 아래코드 하나없어서 시간초과났음
	if (max == alphabet_kind.size()) {
		printf("%d", max);
		exit(0);
	}
}



int main() {
	int stack = 0;
	scanf("%d %d", &R, &C);
	std::string tmp;
	for (int i = 0; i < R; i++) {
		std::cin >> tmp;
		alphabet.push_back(tmp);
	}
	alphabet_num();
	calculate(0, 0, stack);
	printf("%d", max);
}

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> alphabet;
std::string alphabet_kind;
std::string pass_alphabet;
int max = 0;
int R, C;

//�������� ��ü�� �������� ������ ��������
//��Ʈ��ŷ�� ���� �� Ǯ������ �ð��ʰ��� ������
//������ ���ĺ��� ������ ��� Ž���߾ ��Ʈ��ŷ���� �ٽ� �ǵ��ư��⶧��
//�̶� ���ĺ��� ��� ������ ���� alphabet_kind�� ���� �ش� size�� ������
//�湮�� �� �ִ� ��� ���ĺ��� �湮�� �������� �ٷ� print�ϰ� �����ϸ� ��.

//c���� ������ �Ǵ��� ����� �ڵ�
bool is_ok_passed(char c) {
	for (int i = 0; i < pass_alphabet.size(); i++) {
		if (pass_alphabet[i] == c) return false;
	}
	return true;
}

//���ĺ� ���� �˷��ִ� �ڵ�
void alphabet_num() {
	for (int i = 0; i < alphabet.size(); i++) {
		alphabet_kind += alphabet[i];
	}
	sort(alphabet_kind.begin(), alphabet_kind.end());
	alphabet_kind.erase(std::unique(alphabet_kind.begin(), alphabet_kind.end()), alphabet_kind.end());

}

//���������� ���°� �������� �˷��ִ� �ڵ�
bool right_is_OK(int row, int col) {

	if (col + 1 < C) {
		if (is_ok_passed(alphabet[row][col + 1])) return true;
	}
	return false;
}

//�������� ���°� �������� �˷��ִ� �ڵ�
bool left_is_OK(int row, int col) {
	if (col - 1 >= 0) {
		if (is_ok_passed(alphabet[row][col - 1])) return true;
	}
	return false;
}

//�������� ���°� �������� �˷��ִ� �ڵ�
bool bottom_is_OK(int row, int col) {
	if (row + 1 < R) {
		if (is_ok_passed(alphabet[row + 1][col])) return true;
	}
	return false;
}

//�Ʒ������� ���°� �������� �˷��ִ� �ڵ�
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
	//�� �Ʒ��ڵ� �ϳ���� �ð��ʰ�����
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

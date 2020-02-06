//���� �ڵ�
//�ٽ��� ���������� ����� ȣ ��  
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

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մ�


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//����� ���� 
//�� ������ �ٽ��� ��Ʈ��ŷ
//���⵵�� 21^n�̱⿡ ���� ���⵵���� ���� �ƴѰŴ� �߶�� ������ ���� �� �� �� 
//����ҋ� �Լ� void���ĸ��� �����ϸ� �������� (�޸� �ʰ�) 
std::vector< std::vector<char> >value;
std::vector<int> find_value;

//S[i][j]�� ���� �����ִ� �Լ�
int i_to_j_sum(int i,int j, std::vector<int> &tmp_push_value) {
	int sum = 0;
	for (int a = i; a < j + 1; a++) {
		sum += tmp_push_value[a];
	}
	return sum;
}

//index�ڸ��� push_value�� ���� ���������� ���� �ùٸ��� Ȯ�����ִ� �Լ�
bool check(int index, int push_value, std::vector<int> &find_value) {
	int sum = 0;
	std::vector<int> tmp_push_value = find_value;
	tmp_push_value[index] = push_value;
	for (int i = 0; i < index+1; i++) {
		for (int j = i; j < index+1; j++) {
			sum=i_to_j_sum(i, j, tmp_push_value);
			if (value[i][j] == '+' && sum <= 0) { 
				tmp_push_value.clear();
				return false; 
			}
			else if (value[i][j] == '-' && sum >= 0) {
				tmp_push_value.clear();
				return false;
			} 
			else if (value[i][j] == '0' && sum!=0) {
				tmp_push_value.clear();
				return false;
			}
		}
	}
	return true;
}

//����� �ݺ������� ���ִ� �Լ�
void calculate(int num, int index) {

	
	if (index == num) {
		for (int i = 0; i < num; i++) {
			printf("%d ", find_value[i]);
		}
		exit(0);
	}

	switch (value[index][index]) {
		case '+':
			for (int i = 1; i < 11; i++) {
				if (check(index,i,find_value)) {
					find_value[index] = i;
					calculate(num, index + 1);
				}
			}
			break;
		case '-':
			for (int i = -10; i < 0; i++) {
				if (check(index,i, find_value)) {
					find_value[index] = i;
					calculate(num, index + 1);
				}
			}
			break;
		case '0':
			find_value[index] = 0;
			calculate(num, index + 1);
			
	}
	

	

}

int main() {
	int num = 0;
	scanf("%d", &num);
	find_value.resize(num);
	value.assign(num, std::vector<char>(num));
	getchar();
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			scanf("%c", &value[i][j]);
		}
	}

	calculate(num,0);
	

}


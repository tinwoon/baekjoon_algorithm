#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//맞춰봐 문제 
//이 문제의 핵심은 백트래킹
//복잡도는 21^n이기에 같은 복잡도여도 답이 아닌거는 잘라야 계산수를 줄일 수 있 음 
//재귀할떄 함수 void형식말고 웬만하면 쓰지말것 (메모리 초과) 
std::vector< std::vector<char> >value;
std::vector<int> find_value;

//S[i][j]의 값을 구해주는 함수
int i_to_j_sum(int i,int j, std::vector<int> &tmp_push_value) {
	int sum = 0;
	for (int a = i; a < j + 1; a++) {
		sum += tmp_push_value[a];
	}
	return sum;
}

//index자리에 push_value가 들어간다 가정했을때 값이 올바른지 확인해주는 함수
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

//계산을 반복적으로 해주는 함수
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


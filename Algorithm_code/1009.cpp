#include <stdio.h>
#include <vector>

using namespace std;



//자리수 별로 반복되는 규칙이 있는 점을 이용
//switch문에  num1만 넣어서 10이상의 케이스는 런타임에러가 뜨게 됨 
//10일 때 출력값이 0이 되도록 한걸 4번 째 실패끝에 알아서 10으로 수정 

int digit_initialize(vector <int> &digit, int num1, int num2) {
	switch (num1%10) {
	case 0:
		digit.clear();
		return 10;

	case 1:
		digit.clear();
		return 1;



	case 2:
		digit.clear();
		digit.push_back(2);
		digit.push_back(4);
		digit.push_back(8);
		digit.push_back(6);
		return (num2 % 4) == 0 ? digit[3] : digit[(num2 % 4) - 1];

	case 3:
		digit.clear();
		digit.push_back(3);
		digit.push_back(9);
		digit.push_back(7);
		digit.push_back(1);
		return (num2 % 4) == 0 ? digit[3] : digit[(num2 % 4) - 1];


	case 4:
		digit.clear();
		digit.push_back(4);
		digit.push_back(6);
		return (num2 % 2) == 0 ? digit[1] : digit[(num2 % 2) - 1];

	case 5:
		digit.clear();
		return 5;

	case 6:
		digit.clear();
		return 6;


	case 7:
		digit.clear();
		digit.push_back(7);
		digit.push_back(9);
		digit.push_back(3);
		digit.push_back(1);
		return (num2 % 4) == 0 ? digit[3] : digit[(num2 % 4) - 1];

	case 8:
		digit.clear();
		digit.push_back(8);
		digit.push_back(4);
		digit.push_back(2);
		digit.push_back(6);
		return (num2 % 4) == 0 ? digit[3] : digit[(num2 % 4) - 1];

	case 9:
		digit.clear();
		digit.push_back(9);
		digit.push_back(1);
		return (num2 % 2) == 0 ? digit[1] : digit[(num2 % 2) - 1];



	}
}



int main() {
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	vector <int> digit;

	vector <int> value;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &num1, &num2);
		value.push_back(digit_initialize(digit, num1, num2));
	}
	for (int i = 0; i < num; i++) {
		printf("%d\n", value[i]);
	}

	return 0;





}


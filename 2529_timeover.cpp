#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

//int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
std::vector<char> enequality_sign;
std::vector<int> result;
std::vector<int> number_of_digit;
int max;
int min;

void printf_rst(int max, int min,int num) {
	std::vector<int> max_result;
	std::vector<int> min_result;
	int tmp = num+1;
	while (tmp--) {
		max_result.push_back(max % 10);
		max /= 10;
		min_result.push_back(min % 10);
		min /= 10;
	}
	

	for (int i = 0; i < num+1; i++) {
		printf("%d", max_result.back());
		max_result.pop_back();
	}
	printf("\n");
	for (int i = 0; i < num+1; i++) {
		printf("%d", min_result.back());
		min_result.pop_back();
	}

}


void how_digit(int i,int num) {
	int tmp = num+1;
	while (tmp--) {
		number_of_digit.push_back(i % 10);
		i= i / 10;
	}
	std::reverse(number_of_digit.begin(), number_of_digit.end());
	
}

bool discriminate_used(int i, std::vector<bool> &is_used) {
	if (is_used[i] == false) {
		is_used[i] = true;
		return true;
	}
	else return false;
}

bool Discriminate() {
	std::vector<bool> is_used(10, false);
	for (int i = 0; i < enequality_sign.size(); i++) {
		switch (enequality_sign[i]) {
			case '<':
				if( (number_of_digit[i] < number_of_digit[i + 1]) && discriminate_used(number_of_digit[i], is_used) ) break;
				else {
					return false;
					break;
				}
			case '>':
				if ( (number_of_digit[i] > number_of_digit[i + 1]) && discriminate_used(number_of_digit[i], is_used)) break;
				else {
					return false;
					break;
				}
		}
	}
	if (discriminate_used(number_of_digit[enequality_sign.size()], is_used)) return true;
	else return false;
	
}



void calculate(int num, int max, int min) {
	for (int i = 0; i < pow(10,num+1); i++) {
		number_of_digit.clear();
		how_digit(i, num);
		if(Discriminate()){
			max = std::max(i, max);
			min = std::min(i, min);
		}
		
	}
	printf_rst(max, min, num);
	//printf("%3d\n%3d\n", max, min);
}


int main() {
	int num = 0;
	scanf("%d", &num);
	int min = pow(10, num + 1) - 1;
	int max = 0;
	for (int i = 0; i < num; i++) {
		getchar();
		char char_enequality;
		scanf("%c", &char_enequality);
		enequality_sign.push_back(char_enequality);
	}
	calculate(num,max,min);

	


	return 0;
}

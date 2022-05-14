#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

std::vector< std::vector<int> >value;
std::vector<int> permutation;
int rst = 0;
//Àç±Í È°¿ë

void calculate(int value,int num) {

	if (value>num) {
		return;
	}
	else if (value == num) {
		rst++;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		calculate(value + i, num);
	}
}


int main() {
	int n = 0; 
	scanf("%d", &n);
	while (n--) {
		int tmp = 0;
		scanf("%d", &tmp);
		calculate(0, tmp);
		printf("%d\n", rst);
		rst = 0;
	}

}

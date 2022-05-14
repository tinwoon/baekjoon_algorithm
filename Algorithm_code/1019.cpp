//start의 값을 ~0, end의 값을 ~9로 맞추고 하나씩 더해주는 방법이다.
//예를 들면 10 ~39인 경우에 
//10, 11, 12, 13, 14, 15, 16, 17, 18, 19
//20, 21, 22, 23, 24, 25, 26, 27, 28, 29
//30, 31, 32, 33, 34, 35, 36, 37, 38, 39
//이렇게 0~9까지가 3번씩 등장하고 반복적인 규칙을 가지게 된다.
//이를 활용해 작성하면 된다.

#include <vector>
#include <iostream>
#include <math.h>

int N;
std::vector<int> rst(10, 0);

void calculate(int start, int end) {
	int digit = 0;

	while (end != 0) {
		if (start % 10 != 0) {

			for (int i = start % 10; i <= 9; i++) {
				rst[i] += pow(10, digit);
			}
			start += 10 - start;
		}
		if (end % 10 != 9) {
			int tmp = end;
			std::vector<int> data(10, 0);
			while (tmp != 0) {
				if (tmp / 10 != 0) data[(tmp / 10) % 10]++;
				tmp /= 10;
			}
			for (int i = end % 10; i >= 0; i--) {
				rst[i] += pow(10, digit);
				for (int j = 0; j < 10; j++) rst[j] += data[j] * pow(10, digit);
			}
			end = end - (end % 10 + 1);
		}
		for (int k = 0; k <= 9; k++) {
			rst[k] += ((end / 10) - (start / 10) + 1) * pow(10, digit);
		}
		if (end < 0) for (int i = 0; i <= 9; i++) rst[i] -= pow(10, digit);
		start /= 10;
		end /= 10;
		digit++;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", rst[i]);
	}
}

int main() {
	scanf("%d", &N);
	calculate(1, N);
}
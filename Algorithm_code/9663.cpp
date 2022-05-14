#include <iostream>
#include <vector>

int num;
std::vector<int> chess;
int stack=0;

//백트래킹 너무 어렵다
bool isPromising(int up) {

	for (int i = 0; i < up; i++) {
		if (chess[i] == chess[up] || abs(chess[up] - chess[i]) == (up-i)) {
			return false;
		}
	}
	return true;
}

void chess_isTrue(int value) {

	if (value == num) {
		stack+=1;
		
	}

	else {
		for (int i = 0; i < num; i++) {
			chess[value] = i;
			if (isPromising(value)) {
				chess_isTrue(value + 1);
			}
		}
	}
	
}




int main() {
	scanf("%d", &num);
	chess.resize(num);
	chess_isTrue(0);
	printf("%d", stack);

}

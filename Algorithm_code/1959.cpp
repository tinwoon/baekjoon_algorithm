#include <iostream>
#include <queue>
#include <limits.h>
#include <tuple>

//달팽이3 문제
//한바퀴 총 4번을 꺽는데 n과m을 두번씩 빼면 되는 규칙이 있다.

int N, M;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };



std::tuple<int, int, long long> calculate() {
	long long num = 0;
	int first_x = 0, first_y = 0;
	while (N >= 3 && M >= 3) {
		N -= 2;
		M -= 2;
		num += 4;
		first_x++;
		first_y++;
	}

	if (N == 1) {
		return std::make_tuple(first_x, first_y + M - 1, num);
	}
	else if (N == 2) {
		return std::make_tuple(first_x + 1, first_y, num + 2);
	}
	else if (M == 1) {
		return std::make_tuple(first_x + N - 1, first_y, num + 1);
	}
	else if (M == 2) {
		return std::make_tuple(first_x + 1, first_y, num + 3);
	}

}

int main() {
	scanf("%d %d", &N, &M);
	auto ans = calculate();
	int x, y;
	long long num;
	std::tie(x, y, num) = ans;
	printf("%lli\n", num);
	printf("%d %d", x + 1, y + 1);
}
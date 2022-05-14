#include <iostream>
#include <vector>

//DP문제 그 이상, 그 이하도 아님 
//9,3,1
int N;
std::vector<int> scv(3, 0);
int HP[61][61][61];
int rst = 100;

void calculate(int scv1, int scv2, int scv3, int num) {

	if (scv1 <= 0 && scv2 <= 0 && scv3 <= 0) {
		if (rst > num) rst = num;
		return;
	}
	if (scv1 < 0) scv1 = 0;
	if (scv2 < 0) scv2 = 0;
	if (scv3 < 0) scv3 = 0;

	if (HP[scv1][scv2][scv3] <= num && HP[scv1][scv2][scv3] != 0) return;

	HP[scv1][scv2][scv3] = num;

	calculate(scv1 - 9, scv2 - 3, scv3 - 1, num + 1);
	calculate(scv1 - 9, scv2 - 1, scv3 - 3, num + 1);
	calculate(scv1 - 3, scv2 - 9, scv3 - 1, num + 1);
	calculate(scv1 - 3, scv2 - 1, scv3 - 9, num + 1);
	calculate(scv1 - 1, scv2 - 9, scv3 - 3, num + 1);
	calculate(scv1 - 1, scv2 - 3, scv3 - 9, num + 1);

}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &scv[i]);
	}

	calculate(scv[0], scv[1], scv[2], 0);
	printf("%d", rst);
}

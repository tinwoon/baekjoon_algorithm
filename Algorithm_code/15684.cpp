#include <iostream>
#include <vector>
#include <queue>

int N, M, H;
std::vector< std::vector<bool> > ladder;
std::vector<int> ladder_value;

bool ladder_is_ok(std::vector< std::vector<bool> > &ladder) {
	for (int i = 1; i <= N; i++) {
		int k = i;
		for (int j = 1; j <= H; j++) {
			if ( k - 1 >= 1 && (ladder[j][k - 1] || ladder_value[(j - 1) * (N - 1) + (k - 2)] == 1) ) {
				if (k + 1 <= N && (ladder[j][k] || ladder_value[(j - 1) * (N - 1) + (k - 1)] ) ) return false;
				k = k - 1;
			}
			else if (k + 1 <= N && (ladder[j][k] || ladder_value[(j - 1) * (N - 1) + (k - 1)] ) ) {
				k = k + 1;
			}
		}
		if (k != i) return false;
	}
	return true;
}

int calculate() {
	for (int num_ladder = 0; num_ladder <= 3; num_ladder++) {
		ladder_value.assign((N - 1) * H, 0);

		//사다리 개수를 0개에서 3개까지 넣는 수열
		for (int k = 0; k < num_ladder; k++) {
			//if (ladder_value.size() - 1 - k < 0)
			if (ladder_value.size() - 1 < k) break;
			ladder_value[ladder_value.size() - 1 - k] = 1;
		}

		do {
			if (ladder_is_ok(ladder)) return num_ladder;
		} while (std::next_permutation(ladder_value.begin(),ladder_value.end()));

	}
	
	return -1;
}

int main() {
	scanf("%d %d %d", &N, &M, &H);
	ladder.assign(H + 1, std::vector<bool>(N + 1, 0));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ladder[a][b] = true;
	}
	printf("%d", calculate());

}

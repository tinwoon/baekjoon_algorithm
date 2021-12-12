#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//16986 인싸가위바위보 문제
//논리가 까다로운 구현문제라 어려웠던 문제이다.
//분기별로 주석을 달아논대로 이해하면 사실 어렵지 않은 dfs용 백트래킹 문제

int N, K;
std::vector< std::vector<int> > graph;
//경희, 민호의 값
std::vector< std::vector<int> > g_m(2, std::vector<int>(20, 0));
bool ans = false;

//지우가 이긴 횟수, 경희가 이긴 횟수, 민호가 이긴 횟수, 지우가 낸 인싸가위바위보 종류(비트마스킹), 승자(0번 지우, 1번 경희, 2번 민호), 새로 들어온 사람(0번 지우, 1번 경희, 2번 민호), 경희의 참여횟수, 민호의 참여횟수
void calculate(int win_j, int win_g, int win_m, int submit, int A, int B, int turn_g, int turn_m) {
	
	//이미 지우가 이긴 답이 있거나, 경희, 민호가 이긴 경우는 바로 종료
	if (ans || win_g == K || win_m == K) return;

	//지우가 이겼으면
	if (win_j == K) {
		ans = true;
		return;
	}
	
	//현 차례가 경희와 민호의 싸움인 경우(사람은 0번은 지우, 1번은 경희, 2번은 민호를 뜻한다)
	if (A != 0 && B != 0) {
		//경희가 낼 것(0번 인덱스)
		int g_turn = g_m[0][turn_g] - 1;
		//민호가 낼 것(1번 인덱스)
		int m_turn = g_m[1][turn_m] - 1;
		//경희가 민호에게 이긴다면
		if (graph[g_turn][m_turn] == 2) calculate(win_j, win_g + 1, win_m, submit, 1, 0, turn_g + 1, turn_m + 1);
		//A가 B에게 진다면
		else if (graph[g_turn][m_turn] == 1 || graph[g_turn][m_turn] == 0) calculate(win_j, win_g, win_m + 1, submit, 2, 0, turn_g + 1, turn_m + 1);
	}
	//현 차례에 지우가 있는 경우
	else {
		//경희이면 1번, 민우면 2번이 들어갈 것이다.
		int else_person = A != 0 ? A : B;

		int else_turn = g_m[else_person - 1][else_person == 1 ? turn_g : turn_m] - 1;
		for (int k = 0; k < N; k++) {
			//이미 지우가 낸 거를 또 내는 거라면 continue;
			if (submit & (1 << k)) continue;
			//지우가 낼 가위바위보의 종류
			int j_turn = k;
			
			//만약 지우랑 다른사람이랑 했을 때 지우가 이긴다면
			if (graph[j_turn][else_turn] == 2) calculate(win_j + 1, win_g, win_m, submit | (1 << k), 0, else_person == 1 ? 2 : 1, else_person == 1 ? turn_g + 1 : turn_g, else_person == 2 ? turn_m + 1 : turn_m);
			//만약 지우랑 다른사람이랑 했을 때 지우가 진다면
			else calculate(win_j, else_person == 1 ? win_g + 1 : win_g, else_person == 2 ? win_m + 1 : win_m, submit | (1 << k), else_person, else_person == 1 ? 2 : 1, else_person == 1 ? turn_g + 1 : turn_g, else_person == 2 ? turn_m + 1 : turn_m);
		}
	}
	
}

int main() {
	scanf("%d %d", &N, &K);
	graph.assign(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 20; j++) {
			scanf("%d", &g_m[i][j]);
		}
	}

	calculate(0, 0, 0, 0, 0, 1, 0, 0);
	printf("%d", ans);
	
}
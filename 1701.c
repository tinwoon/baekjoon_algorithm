#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

//kmp 알고리즘 중 getpi를 활용하는 문제이다.
//getpi 함수의 경우 접미사, 접두사가 일치할 경우 해당 일치한 값의 길이를 넣은 값이다.
//예를 들어 abcabcabc의 경우 pi[8]의 값은 abcabc, abcabc로 일치함으로 6이된다.
//중간에 값이 중복되는 것까지 포함하여 계산한다는 것이 핵심이니 꼭 기억해야한다.
//특히, 32번째 줄 j = pi[j-1]로 초기화 하는 이유는 모를 수도 있는데
//abcabcabc의 경우 안맞았으면 이제까지의 접두사 내에서도 또 접미사 접두사가 일치하는 경우가 있다.
//따라서 접두사 부분부터 시작한 내역이 맞지 않으면 다음번 탐색은 접미사부터 시작할 수 있도록 j = pi[j-1]로 나타낸 것이다.

char S[5001];
int pi[5001];
int ans = 0;

void f_ans(int len) {
	for (int i = 0; i < len; i++) {
		ans = std::max(ans, pi[i]);
	}
}

void get_pi(int size) {
	for (int start = 0; start < size; start++) {
		memset(pi, 0, sizeof(pi));
		char* c_s = &S[start];
		int len = strlen(c_s);
		int j = 0;

		for (int i = 1; i < size; i++) {
			while (j > 0 && c_s[i] != c_s[j]) {
				j = pi[j - 1];
			}
			if (c_s[i] == c_s[j]) pi[i] = ++j;
		}
		f_ans(len);
	}
}

int main() {
	scanf("%s", S);
	get_pi(strlen(S));
	printf("%d", ans);
}
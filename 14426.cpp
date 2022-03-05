#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//11426 접두사 찾기 문제
//마찬가지로 binarysearch를 통해 구현
//다만 기존의 bsearch는 사용 불가했다.

int N, M;
char(*S)[501];
int ans;

//값이 있으면 true, 없으면 false
//비교할 데이터와 비교할 데이터의 길이
int b_search(int begin, int end, char* s, int length_s) {
	while (begin <= end) {
		int mid = (begin + end) / 2;
		int flag = 1;
		for (int k = 0; k < length_s; k++) {
			if (flag && (S[mid][k] != s[k])) {
				if (S[mid][k] > s[k]) end = mid - 1;
				else begin = mid + 1;
				flag = 0;
			}
		}
		if (flag) return 1;
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);
	S = (char(*)[501])malloc(sizeof(char) * N * 501);
	for (int k = 0; k < N; k++) {
		scanf("%s", S[k]);
	}

	qsort(S, N, sizeof(char) * 501, (int (*)(const void*, const void*))strcmp);

	for (int k = 0; k < M; k++) {
		char cmp_s[501];
		scanf("%s", cmp_s);
		if (b_search(0, N - 1, cmp_s, strlen(cmp_s))) {
			ans++;
		}
	}
	printf("%d", ans);
}
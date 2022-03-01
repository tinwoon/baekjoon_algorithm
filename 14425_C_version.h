#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;

char (*S)[501];
char cmp[501];
int ans;

int main() {
	scanf("%d %d", &N, &M);
	S = (char(*)[501])malloc(sizeof(char) * 501 * N);
	for (int k = 0; k < N; k++) {
		scanf("%s", S[k]);
	}
	qsort(S, N, sizeof(char) * 501, (int (*) (const void *, const void *))strcmp);
	for (int k = 0; k < M; k++) {
		scanf("%s", cmp);
		if (bsearch(cmp, S, N, sizeof(char) * 501, (int (*) (const void*, const void*))strcmp)) ans++;
	}
	printf("%d", ans);
}
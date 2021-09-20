#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1316 그룹단어 체커 문제
//어려운건 아니지만 c언어 복습을 위한 단계

int is_checked[26];
int N;
int ans;

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		memset(is_checked, 0, sizeof(is_checked));
		char* str = (char*)calloc(101, sizeof(char));
		scanf("%s", str);
		int flag = 1;
		is_checked[str[0] - 'a'] = 1;
		for (int size = 1; size < strlen(str); size++) {
			if (is_checked[str[size] - 'a'] && (str[size - 1] - 'a' != str[size] - 'a')) {
				flag = 0;
			}
			is_checked[str[size] - 'a'] = 1;
		}
		if (flag) ans++;
		free(str);
	}
	printf("%d", ans);
}
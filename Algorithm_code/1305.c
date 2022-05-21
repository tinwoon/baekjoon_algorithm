#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//백준 1305 광고 풀이 문제 일부
//풀이 방법 하기와 같이 설계 예정 (통과함)
//플레 4만큼의 어려운 문제는 아닌 걸로 생각 됨.
//앞 부분의 접두사와 뒤의 접미사의 일치 개수가 최대일수록 해당 광고의 길이가 짧다.
//ex aabaa하면 접두사 접미사가 aa에 해당하므로 aab가 가장 짧은 길이가 된다.
//결국엔 getpi를 통해 접두사 접미사의 최대 크기를 구하고 계산하는 방식
//즉, 접두사 접미사가 일치하는 개수 + 접두사 접미사가 일치하지 않는 가운데의 개수를 더한 값이 return되도록 구현 필요

#define MAX 1000001
int L;
char data[MAX];
int* pi;

int get_pi(){
	int j = 0;
	for (int i = 1; i < L; i++) {
		while (j > 0 && data[i] != data[j]) j = pi[j - 1];
		if (data[i] == data[j]) pi[i] = ++j;
	}

	return L - pi[L-1];
}

int main() {
	scanf("%d", &L);
	pi = (int*)calloc(L, sizeof(int));
	scanf("%s", data);
	printf("%d", get_pi());
}
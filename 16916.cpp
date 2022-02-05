#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000001

//백준 16919 부분 문자열 문제 
//보자마자  strstr이 떠올랐던 문제 
//접두사 접미사를 기반으로한 KMP 알고리즘으로 풀이
//strstr이 KMP 알고리즘으로 구성되어 있다. 

char S[MAX];
char P[MAX];

int main() {
	scanf("%s", S);
	scanf("%s", P);
	printf("%d", strstr(S, P) != NULL ? 1 : 0);
}

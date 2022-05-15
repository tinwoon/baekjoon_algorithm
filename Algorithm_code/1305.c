#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//백준 1305 광고 풀이 문제 일부

int L;
char p[1000000];
int* pi;

void getpi() {   
	int j = 0;
	for (int i = 1; i < L; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return; 
}

int main() {
	scanf("%d", &L);
	pi = (int*)calloc(L, sizeof(pi));
	scanf("%s", p);
	getpi();
}
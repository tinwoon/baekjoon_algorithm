#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000001

//���� 16919 �κ� ���ڿ� ���� 
//���ڸ���  strstr�� ���ö��� ���� 
//���λ� ���̻縦 ��������� KMP �˰������� Ǯ��
//strstr�� KMP �˰������� �����Ǿ� �ִ�. 

char S[MAX];
char P[MAX];

int main() {
	scanf("%s", S);
	scanf("%s", P);
	printf("%d", strstr(S, P) != NULL ? 1 : 0);
}

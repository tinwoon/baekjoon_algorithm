#include <stdio.h>
#include <stdlib.h>

//2163 ���ݸ� �ڸ��� ����

int N, M;

int main()
{
	scanf("%d %d", &N, &M);
	printf("%d", N - 1 + (N * (M - 1)));
	return 0;
}
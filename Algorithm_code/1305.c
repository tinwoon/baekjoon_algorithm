#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� 1305 ���� Ǯ�� ���� �Ϻ�
//Ǯ�� ��� �ϱ�� ���� ���� ����
//�� �κ��� ���λ�� ���� ���̻��� ��ġ ������ �ִ��ϼ��� �ش� ������ ���̰� ª��.
//ex aabaa�ϸ� ���λ� ���̻簡 aa�� �ش��ϹǷ� aab�� ���� ª�� ���̰� �ȴ�.
//�ᱹ�� getpi�� ���� ���λ� ���̻��� �ִ� ũ�⸦ ���ϰ� ����ϴ� ���
//��, ���λ� ���̻簡 ��ġ�ϴ� ���� + ���λ� ���̻簡 ��ġ���� �ʴ� ����� ������ ���� ���� return�ǵ��� ���� �ʿ�


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
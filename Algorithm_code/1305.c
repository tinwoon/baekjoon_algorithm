#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� 1305 ���� Ǯ�� ���� �Ϻ�
//Ǯ�� ��� �ϱ�� ���� ���� ���� (�����)
//�÷� 4��ŭ�� ����� ������ �ƴ� �ɷ� ���� ��.
//�� �κ��� ���λ�� ���� ���̻��� ��ġ ������ �ִ��ϼ��� �ش� ������ ���̰� ª��.
//ex aabaa�ϸ� ���λ� ���̻簡 aa�� �ش��ϹǷ� aab�� ���� ª�� ���̰� �ȴ�.
//�ᱹ�� getpi�� ���� ���λ� ���̻��� �ִ� ũ�⸦ ���ϰ� ����ϴ� ���
//��, ���λ� ���̻簡 ��ġ�ϴ� ���� + ���λ� ���̻簡 ��ġ���� �ʴ� ����� ������ ���� ���� return�ǵ��� ���� �ʿ�

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
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//9935 ���ڿ� ���� ����
//strstr�� ����� kmp�� �ƴ� �� ���ڶ� ã���� �ϴ� ������ �� ���ڶ� ������ �̶� ���� ������ ���ؼ� �ε����� �����ϴ� ����
//kmp�� ����ϸ� ������ �ð��ʰ��� �߻��Ѵ�.

char data[1000001];
char boomb[37];

int main() {

	char ans[1000001] = "";

	scanf("%s", data);
	scanf("%s", boomb);

	int len = strlen(data);
	int boomb_len = strlen(boomb);

	int index = 0;

	for (int k = 0; k < len; k++) {
		ans[index++] = data[k];
		if (ans[index - 1] == boomb[boomb_len - 1]) {
			bool flag = true;
			for (int size = 0; size < boomb_len; size++) {
				if (ans[index - 1 - size] != boomb[boomb_len - 1 - size]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				index -= boomb_len;
			}
		}
	}

	if (index == 0) printf("FRULA\n");
	else {
		ans[index] = '\n';
		int find_index = 0;
		while (ans[find_index] != '\n') {
			printf("%1c", ans[find_index++]);
		}
		printf("\n");
	}




}
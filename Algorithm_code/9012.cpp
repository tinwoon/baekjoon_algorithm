#include <iostream>
#include <stack>
#include <string.h>

//stack�� ���� ����
//char���� ���� ��Ʈ���� ���Ҷ� ���ڿ��� �ƴ� char �迭�ϳ�
//�� data[1] �̷� ������ ���� �����̱� ������ "�� �ƴ� '�� �����
//������� data[i]=="(" �� �Ұ���
//���� data�迭�ε��� ������ ���ڿ��� �ƴϱ� ������ strcmp�� �ȵ�
//���� ��� strcmp(&data[i],'(')==0 �ȵ�. data[i]=='('�� �ؾ���
//���� strlen(data)�ϸ� ������ ����� "\n"���� �� 
//�����Ͱ� ���ϴ� ���̿� ���� 1�þ�Ŷ� ����������
//���� �츮�� ���ϴ� ������ ������.
//������� char data[51]�� "abc"�� �ְ� strlen�� �ϸ� ���̰� 4���ƴ� 3��
int right_VPS(char data[51]) {
	std::stack<int> v;
	for(int i = 0; i < strlen(data);i++) {
		
		if (data[i]=='(') {
			v.push(1);
		}
		else if (!v.empty()) {
			v.pop();
		}
		else return false;
			
	}
	if (v.empty()) return true;
	else return false;
}



int main() {
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		char data[51];
		scanf("%s", data);
		printf("%s\n", right_VPS(data) == true ? "YES" : "NO");
		
	}



}

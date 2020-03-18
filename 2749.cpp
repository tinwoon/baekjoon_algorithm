#include<iostream>

long long data[1500050];

//���� 2749 �Ǻ���ġ ����
//�ǻ�� �ֱ��� ������� �˰��� ���� �˾ƾ߸� Ǯ �� �ִ� ����
//�˰����� ����������� ���� ������
void fibonacci() {
	data[0] = 0;
	data[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		data[i + 2] = (data[i + 1] + data[i]) % 1000000;
	}
}

int main() {
	long long n;
	scanf("%lli", &n);
	fibonacci();
	printf("%d\n",data[n % 1500000]);

}


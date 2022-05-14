#include <iostream>
#include <queue>

//�̰� �� ������ �ʿ�����
//�ùķ�����ó�� Ǯ����
//���� 11279�� �ִ� ��
//�ڿ����� ������ �����Ϳ� �ְ�
//0�� ������ ������ �־��� ������ �� ���� ���� ���� ��
int main() {
	int n;
	scanf("%d", &n);
	std::priority_queue< int, std::vector<int>, std::less<int> >data;
	while (n--) {
		int value;
		scanf("%d", &value);
		if (value > 0) {
			data.push(value);
		}
		else if (data.size() != 0) {
			printf("%d\n", data.top());
			data.pop();
		}
		else printf("0\n");
	}
	return 0;
}

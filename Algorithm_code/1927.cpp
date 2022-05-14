#include <iostream>
#include <queue>

//�̰� �� ������ �ʿ�����
//�ùķ�����ó�� Ǯ����
//���� 1927
//���� 11279�� �ִ� ������ less�� greater�� �ٲ��ֱ⸸ �ϸ� �Ǵ� ����
//�ڿ����� ������ �����Ϳ� �ְ�
//0�� ������ ������ �־��� ������ �� ���� ���� ���� ��
int main() {
	int n;
	scanf("%d", &n);
	std::priority_queue< int, std::vector<int>, std::greater<int> >data;
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
}

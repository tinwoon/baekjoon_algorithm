#include <iostream>
#include <queue>

//�̰� �� ������ �ʿ�����
//�ùķ�����ó�� Ǯ����
//���� 11286
//pair�� ���� ����
//priority_queue�� ��ó���� ���� �������� �����ϱ� ������
//pair�� �ְ� �� ���� abs�� ������ ��°���� ������ ������ �Ѵ��� �ֱ�
//priority_queue�� first�ε����� �������� ������ ������ ���°��� second�ε����� ����ϸ� ��
int main() {
	int n;
	scanf("%d", &n);
	std::priority_queue< std::pair<int,int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > >data;
	while (n--) {
		int value;
		scanf("%d", &value);
		if (value != 0) {
			data.push({abs(value),value});
		}
		else if (data.size() != 0) {
			printf("%d\n", data.top().second);
			data.pop();
		}
		else printf("0\n");
	}
}

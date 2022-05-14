#include <iostream>
#include <algorithm>
#include <queue>
 
//���� 1655�� �߰����� ���ϴ� ��
//������ ������� �����ϴ� ��ó��
//�ܼ��� ���͸� ���������� sort�ϴ� ����� 1000000���� ������ �ؾ��ϱ� ������ �ð��ʰ��� �߻��Ѵ�.
//���� �켱���� ť�� ���� �ϳ��� �ִ��� ������ �켱���� ť �ϳ��� �ּڰ��� ������ �켱����ť�� �����Ͽ�
//�׻� �ִ��� ������ �켱����ť�� top���� ū ���� �ּڰ��� ������ �켱����ť�� �־��ָ� top�� �׻� �߰� ���̴�.
//���� ��� 12345�� �ִٸ� 123������ �ִ��� ������ �켱����ť 45������ �ּڰ��� ������ �켱���� ť�� �־��ָ� �ִ��� ������ �켱����ť�� �߰������� �̿��Ѵ�.
int main()
{
	int n;
	std::priority_queue<int, std::vector<int>, std::less<int> > max_first;
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_first;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (max_first.size() == min_first.size()) {
			max_first.push(tmp);
		}
		else {
			min_first.push(tmp);
		}
		if (min_first.size() == 0);//min_first�� �����Ͱ� ��� ������ ���� ���ǹ� "if (max_first.top() > min_first.top())"�� 
		//min_first.top()�� �� ���� �����Ͽ� �ε��� ������ ������ else if���� �������� �ʰ� �׳� �ѱ⵵�� �����ϱ� ���� 
		else if (max_first.top() > min_first.top()) {
			int tmp=max_first.top();
			max_first.pop();
			max_first.push(min_first.top());
			min_first.pop();
			min_first.push(tmp);
		}
		printf("%d\n", max_first.top());
	}
	return 0;
}

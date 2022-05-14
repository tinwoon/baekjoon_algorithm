// baekjoon.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>

using namespace std;


	unsigned int sum=0;
	vector<int> v_from;
	vector<int> v_to;






void Hanoi_start(int how_much, int from, int to, int tmp) {
		if (how_much == 1) {//���� ���� �ϳ�¥�� ��� 
			v_from.push_back(from);
			v_to.push_back(to);
			sum++;
		}
		else {
			Hanoi_start(how_much-1, from, tmp, to);
			v_from.push_back(from);
			v_to.push_back(to);
			sum++;
			Hanoi_start(how_much-1, tmp, to, from);
		}
	}



int main()
{

	unsigned int n;
	scanf("%d",&n);
	Hanoi_start(n, 1, 3, 2);
	printf("%d\n", sum);
	for(unsigned int i=0;i<v_from.size();i++){
		printf("%d %d\n",v_from[i],v_to[i]);
	}

}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.


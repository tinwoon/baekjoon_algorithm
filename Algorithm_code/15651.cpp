#include <iostream>
#include <vector>


//��Ʈ��ŷ�� ����ġ������ �� ���
//������ ������� ����
//��� �׸���� �ٸ��� ��� ��θ� �˻��Ѵٴ� ������ ���Ʈ������
//�ٸ� ����������� �ٸ��� �Դ����� �ǵ��ư� �˻��Ѵٴ� ������ dfs��
//��ü���� Ʋ�� ������� �� for���� ���� ����ϴ� ������(******�ſ� �߿�******)

void calculate(int n, int m, std::vector<int> &v,int index) {
	if (index == m) {

		for (int i = 0; i < m; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		index = 0;
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			v[index] = i;
			calculate(n, m, v, index+1);
		}
	}
}


int main() {
	int n, m;
	std::vector<int> v;
	scanf("%d %d", &n, &m);
	v.resize(m);
	calculate(n, m, v, 0);


}



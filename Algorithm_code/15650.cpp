#include <iostream>
#include <vector>


//õ�� �� ��ü
//������ �̷��� ��� �ڽ��� ����.

void calculate(int index,int n, int m,std::vector<int> &v) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = index == 0 ? 1 : v[index - 1] + 1; i <= n; i++) {
		v[index]=i;
		calculate(index+1,n,m,v);
	}
	
}



int main() {
	int m,n;
	std::vector<int> v;
	scanf("%d %d", &n, &m);
	v.resize(m);
	calculate(0, n, m, v);

}

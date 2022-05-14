#include <iostream>
#include <vector>


//백트래킹은 가지치기임을 꼭 기억
//가지를 뻗어나가는 구조
//대신 그리디와 다르게 모든 경로를 검색한다는 점에서 브루트포스임
//다만 브루투포스와 다르게 왔던길을 되돌아가 검색한다는 점에서 dfs임
//전체적인 틀은 기저사례 후 for문을 통해 재귀하는 형식임(******매우 중요******)

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



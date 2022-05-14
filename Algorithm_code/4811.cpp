#include <iostream>
#include <vector>


//dp를 통해 구 현 
//처음에 재귀적으로 구현했으나 시간적 오류로 실패
//후에 재귀적으로 dp를 통해 구현 함  


int n;
std::vector< std::vector<long long> >dp(31, std::vector<long long>(31));
long long dfs(int W, int H) {

	if (dp[W][H])
		return dp[W][H];

	if (W == 0)
		return 1;

	dp[W][H] = dfs(W - 1, H + 1);
	if (H > 0)
		dp[W][H] += dfs(W, H - 1);

	return dp[W][H];
}

int main() {

	
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;

		printf("%lli\n", dfs(n, 0));
	}

	return 0;
}






//#include <iostream>
//#include <vector>
//
//static int stack;
//static int num;
//
//std::vector< std::vector<int> > dp(num,std::vector<int>(num));
//
//
//
//
//void pill(int w, int h, int n) {
//	if ((w < 0) || (h < 0)) {
//		return;
//	}
//
//	if (n == 0) {
//		stack++;
//	}
//
//
//	pill(w - 1, h + 1, n - 1);
//
//	pill(w, h - 1, n - 1);
//
//	
//
//}
//
//
//
//int main() {
//	
//	while (1) {
//		
//		scanf("%d", &num);
//
//		if (num == 0) break;
//		stack = 0;
//		pill(num, 0, num * 2);
//		printf("%d\n", stack);
//
//	}
//}

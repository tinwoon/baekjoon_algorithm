#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;



//최장 공통수열
// 문제의 원리는 간단
//acaykp와 capcak가 있다면
//acaykp 와 c까지의 lcs는 1
//acaykp 와 ca까지의 lcs는 2
//acaykp 와 cap까지의 lcs는 3
//acaykp 와 capc까지의 lcs는 3
 //acaykp 와 capca까지의 lcs는 4
 //acaykp 와 capcak까지의 lcs는 4이다
 //즉 알파벳이 하나씩 추가됬을경우 값을 비교해서 있으면 1을 추가하는 원리이다. 


int main() {

	char s1[1001];
	char s2[1001];

	scanf("%s %s", s1, s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	
	vector< vector<int> >dp;
	vector<int> v(len2+1,0);
	for (int i = 0; i < len1 + 1; i++) {
		dp.push_back(v);
	}
	

	int i, j, ans = 0;


	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d\n", dp[len1][len2]);


	return 0;
}

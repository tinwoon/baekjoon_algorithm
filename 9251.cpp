#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;



//���� �������
// ������ ������ ����
//acaykp�� capcak�� �ִٸ�
//acaykp �� c������ lcs�� 1
//acaykp �� ca������ lcs�� 2
//acaykp �� cap������ lcs�� 3
//acaykp �� capc������ lcs�� 3
 //acaykp �� capca������ lcs�� 4
 //acaykp �� capcak������ lcs�� 4�̴�
 //�� ���ĺ��� �ϳ��� �߰�������� ���� ���ؼ� ������ 1�� �߰��ϴ� �����̴�. 


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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//dp�����̴�.
//�ϴ� �� ó���� �����ٽ��� ��Ʈ������ ������ �迭�� �����Ѵ�
//1 3 2 4 6 10 9 7 ���� ��� 1 2 3 4 6 7 9 10���� ������ �迭�� ������ ��
//lis�˰����� ���� �����Ѵ�.
//�������� ���̴� ���� ������ ����.
//ù��°�� ������ �������� �������� �ε����� ������ ���� �ε��� ���� ������ ����������
//�������� ����� ���� ������� 1�ε����� ���� 8�ε� 2�� �ε����� 2�̸�
//�� �Ŀ� �ִ� �ε����� ���ڰ� ������ �ε����� ���ں��� ������ �����ϱ⿡ ���������ʴ´�
//�̸� ��������� �ִ��� ���� ���Ͽ� lis�� ���̸� ���Ѵ��� ���־��ϴ� �ּҰ����̱� ������ 
//���� ���� �� �������� �������� ���ָ� ���־� �ϴ� �����̴�.
int calculate(int num, vector< vector<int> >data) {
	int max = 0;
	vector<int> dp;
	dp.resize(num+1);
	for (int i = 1; i <= num; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (data[i][1] > data[j][1]) {
				if (min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i])
			max = dp[i];
	}
	return max;
}


int main() {
	int num = 0;
	scanf("%d",&num);
	vector< vector<int> >data;
	vector<int> v;

	for (int i = 1; i <= num; i++) {
		int tmp_1, tmp_2;
		scanf("%d %d", &tmp_1, &tmp_2);
		v.push_back(tmp_1);
		v.push_back(tmp_2);
		data.push_back(v);
		v.clear();
	}
	v.push_back(0);
	v.push_back(0);
	data.insert(data.begin(),v);

	sort(data.begin(), data.end());

	printf("%d", num-calculate(num, data));


}

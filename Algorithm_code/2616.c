#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) a > b ? a : b

//2616 ��������� ����
//��ȭ�� �ۼ��ϴµ� ��ٷο��� ����
//������ �ͳ��� ������ ���� DP ������ index ������ N-1�� �ƴ� N���� �����ؾ� ��Ȱ�� Ǯ�� ����

int N;
int w;
//k�� ��������� N���� ������� ��
int* dp[4];
//���� ���� ���� �迭
int* sum;

int ret_sum(int first, int second) {
    if (first == 0) return sum[second];
    else return sum[second] - sum[first - 1];
}

int calculate() {
    for (int k = 1; k <= 3; k++) {
        dp[k][k * w] = dp[k - 1][k * w - w] + ret_sum(k * w - w + 1, k * w);
        for (int index = k * w + 1; index <= N; index++) {
            dp[k][index] = max(dp[k - 1][index - w] + ret_sum(index - w + 1, index), dp[k][index - 1]);
        }
    }
    return dp[3][N];
}

int main() {
    scanf("%d", &N);
    sum = (int*)calloc(N + 1, sizeof(int));
    for (int k = 1; k <= N; k++) {
        int guest;
        scanf("%d", &guest);
        if (k == 1) sum[k] = guest;
        else sum[k] = sum[k - 1] + guest;
    }
    scanf("%d", &w);
    for (int k = 0; k < 4; k++) {
        dp[k] = (int*)calloc(N + 1, sizeof(int));
    }
    printf("%d", calculate());
}
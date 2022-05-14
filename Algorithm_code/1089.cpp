#pragma warning (disable: 4996)
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

//1089�� ��ŸƮ��ũ Ÿ�� ����
//�� �ڸ������� �� �� �ִ� ����� ���� ��� ���ϴ� �˰����� �����ϰ� ���� ������ �ִ�.
//�ܿ��δ� �� ���� �Ͱ���. 
//�� ���ڸ� ���� ���� �� ���� �����̸� ����.

int N;
char number[10][5][4] = {
   { {"###"},
     {"#.#"},
     {"#.#"},
     {"#.#"},
     {"###"} },

   { {"..#"},
     {"..#"},
     {"..#"},
     {"..#"},
     {"..#"} },

   { {"###"},
     {"..#"},
     {"###"},
     {"#.."},
     {"###"} },

   { {"###"},
     {"..#"},
     {"###"},
     {"..#"},
     {"###"} },

   { {"#.#"},
     {"#.#"},
     {"###"},
     {"..#"},
     {"..#"} },

   { {"###"},
     {"#.."},
     {"###"},
     {"..#"},
     {"###"} },

   { {"###"},
     {"#.."},
     {"###"},
     {"#.#"},
     {"###"} },

   { {"###"},
     {"..#"},
     {"..#"},
     {"..#"},
     {"..#"} },

   { {"###"},
     {"#.#"},
     {"###"},
     {"#.#"},
     {"###"} },

   { {"###"},
     {"#.#"},
     {"###"},
     {"..#"},
     {"###"} },
};

char map[5][40];
double count = 1;
std::vector< std::vector<int> > digit;

//���°�� num����
void calculate(int num) {

    if (num == N) return;

    for (int k = 0; k < 10; k++) {
        int flag = true;
        for (int i = 0; i < 5; i++) {
            if (!flag) break;
            for (int j = 0; j < 3; j++) {
                if (map[i][j + (4 * num)] == '#' && number[k][i][j] == '.') {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) digit[num + 1].emplace_back(k);
    }
    calculate(num + 1);
    return;
}

int main() {
    scanf("%d", &N);
    digit.assign(N + 1, std::vector<int>(0, 0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3 * N + (N - 1); j++) {
            scanf(" %1c", &map[i][j]);
        }
    }
    calculate(0);
    for (int i = 1; i <= N; i++) {
        count *= (double)digit[i].size();
    }
    if (count == 0) printf("-1");
    else {
        double ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += std::accumulate(digit[i].begin(), digit[i].end(), 0) * pow(10, N - i) * (count / (double)digit[i].size());
        }
        std::cout << ans / count << std::setprecision(10);
    }
}

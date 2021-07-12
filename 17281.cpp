#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string.h>

//17281 야구문제

int N;
int ans = 0;
std::vector< std::vector<int> > batter;

void cal_score(int& base, int& score) {
    if (base & (1 << 3)) {
        base = base & ~(1 << 3);
        score++;
    }
}

int calculate() {

    std::vector<int> num_batter(9, 0);
    std::iota(num_batter.begin(), num_batter.end(), 0);

    do {
        //맨 처음 타자가 4번 타자가 아니면
        if (num_batter[3] != 0) continue;
        int out_count = 0;
        int inning = 0;
        int current_batter = 0;
        int score = 0;
        while (inning < N) {
            int base = 0;
            while (out_count != 3) {
                if (batter[inning][num_batter[current_batter]] == 0) out_count++;
                else {
                    for (int hit = 0; hit < batter[inning][num_batter[current_batter]]; hit++) {
                        base = (hit == 0) ? ((base << 1) + 1) : (base << 1);
                        cal_score(base, score);
                    }
                }
                current_batter = (current_batter + 1) % 9;
            }
            out_count = 0;
            inning++;
        }
        ans = std::max(ans, score);
    } while (std::next_permutation(num_batter.begin(), num_batter.end()));
    return ans;
}

int main() {
    scanf("%d", &N);
    batter.assign(N, std::vector<int>(9, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &batter[i][j]);
        }
    }
    printf("%d", calculate());
}
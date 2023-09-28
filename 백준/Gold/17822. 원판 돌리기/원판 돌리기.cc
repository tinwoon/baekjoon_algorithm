#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <set>

int N, M, T;
int sum;
int count;

std::vector< std::vector<int> > rotate;

//1. 같은 원 안의 인접을 삭제해야하고,
//2. 다른 원끼리의 인접을 삭제해야한다.
void remove() {
    std::set< std::pair<int, int> > rm;

    // 1. 같은 원 안의 인접 삭제
    for (int n = 1; n <= N; n++) {
        for (int m = 0; m < M; m++) {
            if ((rotate[n][m] != 0) && (rotate[n][m] == rotate[n][(m + 1) % M])) {
                rm.emplace(std::make_pair(n, m));
                rm.emplace(std::make_pair(n, (m + 1) % M));
            }
        }
    }

    // 2. 다른 원끼리의 인접 삭제
    for (int m = 0; m < M; m++) {
        for (int n = 1; n <= N - 1; n++) {
            if ((rotate[n][m] != 0) && (rotate[n][m] == rotate[n + 1][m])) {
                rm.emplace(std::make_pair(n, m));
                rm.emplace(std::make_pair(n + 1, m));
            }
        }
    }

    if (rm.size()) {
        for (auto itr = rm.begin(); itr != rm.end(); itr++) {
            sum -= rotate[itr->first][itr->second];
            rotate[itr->first][itr->second] = 0;
            count--;
        }
    }
    else {
        float avg = (float)sum / (float)count;
        for (int n = 1; n <= N; n++) {
            for (int m = 0; m < M; m++) {
                int v = ((float)rotate[n][m] > avg) ? -1 : (((float)rotate[n][m] < avg) ? 1 : 0);
                if (rotate[n][m]) {
                    sum += v;
                    rotate[n][m] += v;
                    if (!rotate[n][m]) count--;
                }
            }
        }
    }
}


void rotation(int x, int d, int k) {

    while (k--) {
        for (int idx = x; idx <= N; idx += x) {

            //반시계 방향
            if (d) {
                int s = rotate[idx][0];
                for (int i = 1; i < M; i++) {
                    rotate[idx][i - 1] = rotate[idx][i];
                }
                rotate[idx][M - 1] = s;
            }
            else {
                int e = rotate[idx][M - 1];
                for (int i = M - 1; i >= 1; i--) {
                    rotate[idx][i] = rotate[idx][i - 1];
                }
                rotate[idx][0] = e;
            }
        }
    }

}

int main() {
    scanf("%d %d %d", &N, &M, &T);
    rotate.assign(N + 1, std::vector<int>(M, 0));
    count = N * M;
    int x, d, k;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &rotate[i][j]);
            sum += rotate[i][j];
        }
    }

    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &x, &d, &k);
        rotation(x, d, k);
        remove();
    }

    printf("%d", sum);
}
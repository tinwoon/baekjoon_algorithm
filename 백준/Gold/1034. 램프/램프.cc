#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

int N, M, K;
//v가 있는 개수
std::map<std::string, int> m;
int init;

bool compare(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
    return a.second > b.second;
}

int calculate() {
    int ret = K % 2 ? 0 : init;
    std::vector<int> possible_switch;

    for (int n = 0; (K - (2 * n) >= 0); n++) {
        //스위치 눌러야하는 개수
        int turn_switch_count = K - (2 * n);
        if (turn_switch_count > M) continue;
        possible_switch.emplace_back(turn_switch_count);
    }

    std::vector< std::pair<std::string, int> > d(m.begin(), m.end());
    std::sort(d.begin(), d.end(), compare);

    for (int k = 0; k < d.size(); k++) {
        int zero_count = std::count(d[k].first.begin(), d[k].first.end(), '0');
        if (std::count(possible_switch.begin(), possible_switch.end(), zero_count)) return d[k].second;
    }

    return ret;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        m[str]++;
        if (str == std::to_string(1<<M - 1)) init++;
    }
    scanf("%d", &K);

    printf("%d", calculate());
}
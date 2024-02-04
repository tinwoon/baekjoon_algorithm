#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector< std::vector<int> > dp;
std::string str1, str2;
int m_len;

int calculate() {
    for (int i = 1; i < str1.size(); i++) {
        for (int j = 1; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                m_len = std::max(m_len, dp[i][j]);
            }
        }
    }
    return m_len;
}

int main() {
    std::cin >> str1 >> str2;
    dp.assign(str1.size(), std::vector<int>(str2.size(), 0));
    
    for (int k = 0; k < str1.size(); k++) {
        dp[k][0] = (str1[k] == str2[0]);
    }

    for (int k = 0; k < str2.size(); k++) {
        dp[0][k] = (str2[k] == str1[0]);
    }

    printf("%d\n", calculate());
}
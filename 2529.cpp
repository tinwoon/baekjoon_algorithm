#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//next_permutaition 하나면 이제까지 알고리즘이 모두 필요없음
//기억해두 

bool check(vector<int> &perm, vector<char> &a) {
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '<' && perm[i] > perm[i+1]) {
            return false;
        }
        if (a[i] == '>' && perm[i] < perm[i+1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int k;
    cin >> k;
    vector<char> a(k);
    for (int i=0; i<k; i++) {
        cin >> a[i];
    }
    vector<int> small(k+1);
    vector<int> big(k+1);
    for (int i=0; i<=k; i++) {
        small[i] = i;
        big[i] = 9-i;
    }
    do {
        if (check(small, a)) {
            break;
        }
    } while(next_permutation(small.begin(), small.end()));
    do {
        if (check(big, a)) {
            break;
        }
    } while(prev_permutation(big.begin(), big.end()));
    for (int i=0; i<big.size(); i++) {
        cout << big[i];
    }
    cout << '\n';
    for (int i=0; i<small.size(); i++) {
        cout << small[i];
    }
    cout << '\n';
    return 0;
}

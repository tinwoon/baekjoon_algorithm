#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

//완벽히 이해못함
//line sweep 알고리즘을 사용한다는 점에 주목
struct point {
    int x, y;
    point(int x, int y) :x(x), y(y) {}
    point() {}
    bool operator <(const point &p)const {
        if (y == p.y)return x < p.x;
        return y < p.y;
    }
};
bool cmp(const point &a, const point &b) {
    return a.x < b.x;
}
int getdist(point a, point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int n, x, y, d;
vector<point> vt;
set<point> st;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        vt.push_back(point(x, y));
    }
    sort(vt.begin(), vt.end(), cmp);
    d = 2e9 + 10000000;
    int er = 0;
    for (int i = 0; i < n; i++) {
        for (int j = er; j < i; j++) {
            if ((vt[i].x - vt[j].x)*(vt[i].x - vt[j].x) >d) {
                st.erase(vt[j]);
                er++;
            }
            else
                break;
        }
        int dist = (int)sqrt((double)d) + 1;
        point lo = point(-100010, vt[i].y - dist);
        point hi = point(100000, vt[i].y + dist);
        auto l = st.lower_bound(lo);
        auto r = st.upper_bound(hi);
        for (auto it = l; it != r; it++) {
            d = min(d, getdist(*it, vt[i]));
        }
        st.insert(vt[i]);
    }
    printf("%d\n", d);
    return 0;
}




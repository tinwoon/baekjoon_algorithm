#include <iostream>
#include <vector>
#include <queue>
#include <math.h>


//계속 틀렸던 이유 => 개행문자 좀 넣어라!!!
//자리수 알고리즘 기억할 것

int num = 0;
std::vector<bool> visited(10000, false);
std::vector<char> use(10000, '0');
std::vector<int> from(10000, -1);



void dfs(std::vector<int>& testcase_kind) {
    std::queue<int> q;
    int value = testcase_kind[0];
    visited[value] = true;
    q.push(value);

    while (!q.empty()) {
        int front = q.front();

        if (front == testcase_kind[1]) {
            std::vector<char> tmp;
            for (int i = testcase_kind[1]; i != value; i = from[i]) {
                tmp.push_back(use[i]);
            }
            for (int i = tmp.size() - 1; i >= 0; i--) {
                printf("%c", tmp[i]);
            }
            printf("\n");

            break;
        }
        //D
        if (!visited[(front * 2) % 10000]) {
            int D_front = (front * 2) % 10000;
            from[D_front] = front;
            use[D_front] = 'D';
            visited[D_front] = true;
            q.push(D_front);
        }
        //S
        if (front != 0) {
            if (!visited[front - 1]) {
                int S_front = front - 1;
                from[S_front] = front;
                use[S_front] = 'S';
                visited[S_front] = true;
                q.push(S_front);

            }
        }
        else {
            if (!visited[9999]) {
                from[9999] = front;
                use[9999] = 'S';
                visited[9999] = true;
                q.push(9999);

            }
        }

        //L
        if (front != 0) {
            if (!visited[(front / 1000) + (front % 1000) * 10]) {
                int L_front = (front / 1000) + (front % 1000) * 10;
                from[L_front] = front;
                use[L_front] = 'L';
                visited[L_front] = true;
                q.push(L_front);

            }
            //R
            if (!visited[(front % 10) * 1000 + front / 10]) {
                int R_front = (front % 10) * 1000 + front / 10;
                from[R_front] = front;
                use[R_front] = 'R';
                visited[R_front] = true;
                q.push(R_front);
            }
        }

        q.pop();
    }


}

int main() {
    scanf("%d", &num);

    int A, B;
    std::vector<int> tmp(2, 0);
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &tmp[0], &tmp[1]);
        dfs(tmp);
        visited.assign(10000, false);
        use.assign(10000, '0');
        from.assign(10000, -1);
    }
}

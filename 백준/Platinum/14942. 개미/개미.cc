#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int N;
//cave_num, energy => a번을 2의 b번 올라갔을 때의 굴의 값, energy
std::vector< std::vector< std::pair<int, int> > > parent;
std::vector<int> energy;
//connected[a] = a와 연결된 노드, 해당 노드 간의 이동 시 필요한 에너지
std::vector< std::vector< std::pair<int, int> > > connected;
//상위 노드가 무엇인지 알려면 levels[현재노드]
std::vector<int> levels;
std::vector<bool> visited;


//parent, 1번으로부터 얼마나 멀리 있는지
void dfs(int node, int level) {
    levels[node] = level;
    visited[node] = true;

    for (int k = 0; k < connected[node].size(); k++) {
        if (!visited[connected[node][k].first]) {
            int n_node = connected[node][k].first;
            int move_energy = connected[node][k].second;

            parent[n_node][0] = std::make_pair(node, move_energy);
            dfs(n_node, level + 1);
        }
    }
}

void calculate() {
    printf("1\n");

    //2 ^ 16까지 초기화할 것
    for (int k = 1; k <= 16; k++) {
        for (int node = 2; node <= N; node++) {
            std::pair<int, int> mid_node = parent[node][k - 1];
            if (mid_node == std::make_pair(0, 0)) continue;
            std::pair<int, int> end_node = parent[mid_node.first][k - 1];
            if (end_node == std::make_pair(0, 0)) continue;
            parent[node][k] = std::make_pair(end_node.first, mid_node.second + end_node.second);
        }
    }

    for (int node = 2; node <= N; node++) {
        int ans_node = node;

        for (int depth = 1; depth <= levels[node]; depth++) {
            int bit_depth = depth;
            int bit = 0, essential_energy = 0;
            int start_node = node;

            while (bit_depth) {
                if (bit_depth & 1 << bit) {
                    essential_energy += parent[start_node][bit].second;
                    start_node = parent[start_node][bit].first;
                    bit_depth -= (1 << bit);
                }
                bit++;
            }

            if (essential_energy <= energy[node]) ans_node = start_node;
            else break;
        }
        printf("%d\n", ans_node);
    }
}

int main() {
    scanf("%d", &N);
    energy.assign(N + 1, 0);
    parent.assign(N + 1, std::vector< std::pair<int, int> >(16, std::pair<int, int>()));
    connected.assign(N + 1, std::vector< std::pair<int,int> >());
    levels.assign(N + 1, 0);
    visited.assign(N + 1, false);

    for (int k = 1; k <= N; k++) {
        scanf("%d", &energy[k]);
    }
    for (int k = 0; k < N - 1; k++) {
        int a, b, consume_energy;
        scanf("%d %d %d", &a, &b, &consume_energy);

        connected[a].emplace_back(std::make_pair(b, consume_energy));
        connected[b].emplace_back(std::make_pair(a, consume_energy));
    }

    dfs(1, 0);
    calculate();
}
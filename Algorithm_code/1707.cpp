#include <iostream>
#include <vector>



//의외로 간단하게 풀렸네...

int V, E;
std::vector< std::vector<int> > value;
std::vector<char> visited_color;
bool is_ok;


void dfs(int node, char color) {
	visited_color[node] = color;

	for (int i = 0; i < value[node].size(); i++) {
		if (!visited_color[ value[node][i] ]) {
			dfs(value[node][i], color=='R'? 'B':'R');
		}
		else if (visited_color[value[node][i]] == color) is_ok = false;
	}

}




int main() {

	int test_num;
	scanf("%d", &test_num);
	
	while (test_num--) {
		is_ok = true;
		scanf("%d %d", &V, &E);
		value.assign(V+1, std::vector<int>(0, 0));
		visited_color.assign(V+1,0);
		for (int i = 0; i < E; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			value[a].push_back(b);
			value[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			dfs(i, visited_color[i]?visited_color[i]:'R');
		}
		printf("%s\n", is_ok? "YES":"NO");

	}
}

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;

    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];

        if (visited[next] == false) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            dfs(i);
            count++;
        }
    }

    cout << count;
}
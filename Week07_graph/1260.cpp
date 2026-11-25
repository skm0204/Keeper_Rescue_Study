#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];

        if (visited[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int v) {
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];

            if (visited[next] == false) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << "\n";

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    bfs(v);
}
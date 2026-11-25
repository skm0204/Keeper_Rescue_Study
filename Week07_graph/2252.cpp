#include <bits/stdc++.h>
using namespace std;

vector<int> graph[32001];
int degree[32001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        degree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];

            degree[next]--;

            if (degree[next] == 0) {
                q.push(next);
            }
        }
    }
}
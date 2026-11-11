#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[1001];

int bfs(int start, int end) {
    int dist[1001];

    for (int i = 0; i < 1001; i++) {
        dist[i] = -1;
    }

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) {
            return dist[cur];
        }

        for (auto next : adj[cur]) {
            int v = next.first;
            int w = next.second;

            if (dist[v] != -1) continue;

            dist[v] = dist[cur] + w;
            q.push(v);
        }
    }

    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b, dist;
        cin >> a >> b >> dist;

        adj[a].push_back({b, dist});
        adj[b].push_back({a, dist});
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cout << bfs(a, b) << '\n';
    }

    return 0;
}
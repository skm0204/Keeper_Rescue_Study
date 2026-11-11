#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];
int parent[100001];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    parent[1] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] != 0) continue;

            parent[next] = cur;
            q.push(next);
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
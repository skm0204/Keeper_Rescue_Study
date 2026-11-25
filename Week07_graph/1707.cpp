#include <bits/stdc++.h>
using namespace std;

vector<int> graph[20001];
int color[20001];

bool bfs(int start) {
    queue<int> q;

    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];

            if (color[next] == 0) {
                if (color[current] == 1) {
                    color[next] = 2;
                }
                else {
                    color[next] = 1;
                }

                q.push(next);
            }
            else if (color[next] == color[current]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for (int t = 0; t < k; t++) {
        int v, e;
        cin >> v >> e;

        for (int i = 1; i <= v; i++) {
            graph[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool result = true;

        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                if (bfs(i) == false) {
                    result = false;
                    break;
                }
            }
        }

        if (result == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
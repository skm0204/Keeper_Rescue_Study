#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[20001];
int dist[20001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    int start;
    cin >> start;

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
    }

    int INF = 1000000000;

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (distance > dist[current]) {
            continue;
        }

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first;
            int weight = graph[current][i].second;

            int newDistance = distance + weight;

            if (newDistance < dist[next]) {
                dist[next] = newDistance;

                pq.push({newDistance, next});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
}
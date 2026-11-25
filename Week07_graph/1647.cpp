#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a;
    int b;
    int cost;
};

vector<Edge> edges;
int parent[100001];

bool compare(Edge x, Edge y) {
    return x.cost < y.cost;
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    }

    parent[x] = find(parent[x]);

    return parent[x];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), compare);

    long long result = 0;
    int maxCost = 0;
    int count = 0;

    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int cost = edges[i].cost;

        if (find(a) != find(b)) {
            merge(a, b);

            result += cost;
            maxCost = cost;
            count++;
        }

        if (count == n - 1) {
            break;
        }
    }

    cout << result - maxCost;
}
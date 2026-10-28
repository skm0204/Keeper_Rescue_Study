#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {

        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < N; ++i) {

            int x;
            cin >> x;

            q.push({i, x});
            pq.push(x);
        }

        int count = 0;

        while (!q.empty()) {

            int idx = q.front().first;
            int priority = q.front().second;

            q.pop();

            if (priority == pq.top()) {

                pq.pop();
                count++;

                if (idx == M) {
                    cout << count << endl;
                    break;
                }
            }

            else {
                q.push({idx, priority});
            }
        }
    }

    return 0;
}
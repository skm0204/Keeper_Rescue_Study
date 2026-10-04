#include <iostream>
using namespace std;

const int MAX = 1000001;

int nextStation[MAX];
int prevStation[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int first;
    cin >> first;

    int previous = first;

    for (int i = 1; i < N; i++) {
        int current;
        cin >> current;

        nextStation[previous] = current;
        prevStation[current] = previous;

        previous = current;
    }

    nextStation[previous] = first;
    prevStation[first] = previous;

    while (M--) {
        string command;
        cin >> command;

        if (command == "BN") {
            int i, j;
            cin >> i >> j;

            int next = nextStation[i];

            cout << next << '\n';

            nextStation[i] = j;
            prevStation[j] = i;

            nextStation[j] = next;
            prevStation[next] = j;
        }

        else if (command == "BP") {
            int i, j;
            cin >> i >> j;

            int prev = prevStation[i];

            cout << prev << '\n';

            nextStation[prev] = j;
            prevStation[j] = prev;

            nextStation[j] = i;
            prevStation[i] = j;
        }

        else if (command == "CN") {
            int i;
            cin >> i;

            int remove = nextStation[i];
            int next = nextStation[remove];

            cout << remove << '\n';

            nextStation[i] = next;
            prevStation[next] = i;
        }

        else if (command == "CP") {
            int i;
            cin >> i;

            int remove = prevStation[i];
            int prev = prevStation[remove];

            cout << remove << '\n';

            nextStation[prev] = i;
            prevStation[i] = prev;
        }
    }

    return 0;
}
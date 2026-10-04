#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    cin >> N;

    list<int> line;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        auto it = line.begin();

        int pos = line.size() - num;

        for (int j = 0; j < pos; j++) {
            it++;
        }

        line.insert(it, i);
    }

    for (int x : line) {
        cout << x << " ";
    }

    return 0;
}
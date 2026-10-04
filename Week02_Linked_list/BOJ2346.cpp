#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    cin >> N;

    list<pair<int, int>> balloons;

    for (int i = 1; i <= N; i++) {
        int move;
        cin >> move;

        balloons.push_back({i, move});
    }

    auto it = balloons.begin();

    while (!balloons.empty()) {
        int number = it->first;
        int move = it->second;

        cout << number << " ";

        it = balloons.erase(it);

        if (balloons.empty()) {
            break;
        }

        if (it == balloons.end()) {
            it = balloons.begin();
        }

        if (move > 0) {
            for (int i = 1; i < move; i++) {
                it++;

                if (it == balloons.end()) {
                    it = balloons.begin();
                }
            }
        }
        else {
            for (int i = 0; i < -move; i++) {
                if (it == balloons.begin()) {
                    it = balloons.end();
                }

                it--;
            }
        }
    }

    return 0;
}
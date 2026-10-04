#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> command(N);

    for (int i = 0; i < N; i++) {
        cin >> command[i];
    }

    list<int> cards;

    for (int i = N - 1; i >= 0; i--) {
        int card = N - i;

        if (command[i] == 1) {
            cards.push_front(card);
        }
        else if (command[i] == 2) {
            auto it = cards.begin();

            if (it != cards.end()) {
                it++;
            }

            cards.insert(it, card);
        }
        else {
            cards.push_back(card);
        }
    }

    for (int card : cards) {
        cout << card << " ";
    }

    return 0;
}
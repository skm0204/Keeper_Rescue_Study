#include <iostream>
#include <deque>

using namespace std;

void collectCards(deque<int>& deck,
                  deque<int>& opponent,
                  deque<int>& mine) {

    while (!opponent.empty()) {
        deck.push_front(opponent.front());
        opponent.pop_front();
    }

    while (!mine.empty()) {
        deck.push_front(mine.front());
        mine.pop_front();
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    deque<int> dodo;
    deque<int> suyeon;

    deque<int> dodoGround;
    deque<int> suyeonGround;

    for (int i = 0; i < N; ++i) {

        int a, b;
        cin >> a >> b;

        dodo.push_back(a);
        suyeon.push_back(b);
    }

    for (int i = 0; i < M; ++i) {

        // 도도의 차례
        if (i % 2 == 0) {

            dodoGround.push_back(dodo.back());
            dodo.pop_back();

            if (dodo.empty()) {
                cout << "su" << '\n';
                return 0;
            }
        }

        // 수연이의 차례
        else {

            suyeonGround.push_back(suyeon.back());
            suyeon.pop_back();

            if (suyeon.empty()) {
                cout << "do" << '\n';
                return 0;
            }
        }

        // 도도가 종을 치는 조건
        if ((!dodoGround.empty() &&
             dodoGround.back() == 5) ||
            (!suyeonGround.empty() &&
             suyeonGround.back() == 5)) {

            collectCards(dodo, suyeonGround, dodoGround);
        }

        // 수연이가 종을 치는 조건
        else if (!dodoGround.empty() &&
                 !suyeonGround.empty() &&
                 dodoGround.back() + suyeonGround.back() == 5) {

            collectCards(suyeon, dodoGround, suyeonGround);
        }
    }

    // 최종 승자 확인
    if (dodo.size() > suyeon.size()) {
        cout << "do" << '\n';
    }

    else if (dodo.size() < suyeon.size()) {
        cout << "su" << '\n';
    }

    else {
        cout << "dosu" << '\n';
    }

    return 0;
}
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {

    int N;
    cin >> N;

    deque<int> d;

    for (int i = 0; i < N; ++i) {

        string cmd;
        cin >> cmd;

        if (cmd == "push_front") {
            int x;
            cin >> x;
            d.push_front(x);
        }

        else if (cmd == "push_back") {
            int x;
            cin >> x;
            d.push_back(x);
        }

        else if (cmd == "pop_front") {
            if (d.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << d.front() << endl;
                d.pop_front();
            }
        }

        else if (cmd == "pop_back") {
            if (d.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << d.back() << endl;
                d.pop_back();
            }
        }

        else if (cmd == "size") {
            cout << d.size() << endl;
        }

        else if (cmd == "empty") {
            cout << d.empty() << endl;
        }

        else if (cmd == "front") {
            if (d.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << d.front() << endl;
            }
        }

        else if (cmd == "back") {
            if (d.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << d.back() << endl;
            }
        }
    }

    return 0;
}
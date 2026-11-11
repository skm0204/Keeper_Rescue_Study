#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<string> s;

    for (int i = 0; i < N; i++) {
        string name, state;
        cin >> name >> state;

        if (state == "enter") {
            s.insert(name);
        }
        else {
            s.erase(name);
        }
    }

    for (auto it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}
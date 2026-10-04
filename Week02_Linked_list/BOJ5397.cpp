#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string input;
        cin >> input;

        list<char> password;
        auto cursor = password.begin();

        for (char c : input) {
            if (c == '<') {
                if (cursor != password.begin()) {
                    cursor--;
                }
            }
            else if (c == '>') {
                if (cursor != password.end()) {
                    cursor++;
                }
            }
            else if (c == '-') {
                if (cursor != password.begin()) {
                    auto temp = cursor;
                    temp--;

                    password.erase(temp);
                }
            }
            else {
                password.insert(cursor, c);
            }
        }

        for (char c : password) {
            cout << c;
        }

        cout << '\n';
    }

    return 0;
}
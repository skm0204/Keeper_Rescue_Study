#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    list<char> text;

    for (char c : str) {
        text.push_back(c);
    }

    auto cursor = text.end();

    int M;
    cin >> M;

    while (M--) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (cursor != text.begin()) {
                cursor--;
            }
        }
        else if (command == 'D') {
            if (cursor != text.end()) {
                cursor++;
            }
        }
        else if (command == 'B') {
            if (cursor != text.begin()) {
                auto temp = cursor;
                temp--;

                text.erase(temp);
            }
        }
        else if (command == 'P') {
            char c;
            cin >> c;

            text.insert(cursor, c);
        }
    }

    for (char c : text) {
        cout << c;
    }

    return 0;
}
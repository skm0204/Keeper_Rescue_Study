#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    string str;
    cin >> str;

    stack<char> s;

    int answer = 0;

    for (int i = 0; i < str.size(); ++i) {

        if (str[i] == '(') {
            s.push('(');
        }

        else {
            s.pop();

            if (str[i - 1] == '(') {
                answer += s.size();
            }

            else {
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
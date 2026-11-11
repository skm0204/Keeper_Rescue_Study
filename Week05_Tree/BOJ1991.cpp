#include <iostream>
using namespace std;

char lc[26], rc[26];

void preorder(char node) {
    if (node == '.') return;

    cout << node;
    preorder(lc[node - 'A']);
    preorder(rc[node - 'A']);
}

void inorder(char node) {
    if (node == '.') return;

    inorder(lc[node - 'A']);
    cout << node;
    inorder(rc[node - 'A']);
}

void postorder(char node) {
    if (node == '.') return;

    postorder(lc[node - 'A']);
    postorder(rc[node - 'A']);
    cout << node;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        lc[a - 'A'] = b;
        rc[a - 'A'] = c;
    }

    preorder('A');
    cout << '\n';

    inorder('A');
    cout << '\n';

    postorder('A');
    cout << '\n';

    return 0;
}
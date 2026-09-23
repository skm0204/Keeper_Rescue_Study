#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr;

    for (int i = 0; i< n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i< m; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    for (int x : arr){
        cout << x << " ";
    }


    return 0;
}
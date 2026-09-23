#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    vector<int> sum(n + 1);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;

        cout << sum[end] - sum[start - 1] << endl;
    }

    return 0;
}
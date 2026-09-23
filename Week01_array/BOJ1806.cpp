#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> count(100001, 0);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    int answer = 0;

    for (int right = 0; right < n; right++){
        count[arr[right]]++;

        while (count[arr[right]] > k){
            count[arr[left]]--;
            left++;
        }

        answer = max(answer, right - left + 1);
    }

    cout << answer << endl;

    return 0;
}
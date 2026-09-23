#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i< n; i++){
        cin >> arr[i];
    }

    int x; 
    cin >> x;

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == x){
            count++;
            left++;
            right--;
        }
        else if (sum < x){
            left++;
        }
        else{
            right--;
        }
    }

    cout << count << endl;

    return 0;


}
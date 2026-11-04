#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> map;
    for (int x : nums){
        map[x]++;
    }
    
    if (map.size() >= nums.size()/2 ) return nums.size()/2;
    else return map.size();
}
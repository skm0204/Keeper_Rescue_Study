#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

//해시에 unordered_set과 unordered_map이 사용된다고 해서 문법 찾아보고 사용

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    
    for (string name : participant){
        map[name]++;
    }
    
    for (string finish : completion){
        map[finish]--;
    }
    
    for (auto p : map){
        if (p.second > 0){
            return p.first;
        }
}
}
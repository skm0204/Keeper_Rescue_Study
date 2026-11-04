#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    
    for (int i = 0; i < clothes.size(); ++i){
        m[clothes[i][1]]++;
    }
    
    int answer = 1;
    
    for (auto x : m){
        answer = answer * (x.second + 1);
    }

    return answer-1;
}
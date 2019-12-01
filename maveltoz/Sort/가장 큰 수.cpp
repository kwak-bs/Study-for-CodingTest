/*
https://www.welcomekakao.com/learn/courses/30/lessons/42746
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
    string ans = "";
    vector<string> numToStr;
    
    for(int i : numbers){
        numToStr.push_back(to_string(i));
    }
    
    sort(numToStr.begin(), numToStr.end(), compare);
    
    for(string s : numToStr){
        ans += s;
    }
    
    if(ans[0] == '0') ans = "0";
    
    return ans;
}

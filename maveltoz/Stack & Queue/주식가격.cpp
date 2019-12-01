/*
https://www.welcomekakao.com/learn/courses/30/lessons/42584
*/

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans;

    for(int i = 0; i < prices.size() - 1; i++) {
        int cnt(0); // 가격이 떨어지지 않은 기간을 저장하는 변수

        for(int j = i + 1; j < prices.size(); j++) {
            cnt++;
            
            // 가격이 떨어졌을 경우
            if(prices[i] > prices[j]) {
                ans.push_back(cnt);
                break;
            }
            
            // 가격이 떨어지지 않았을 경우
            if(j == prices.size() - 1) ans.push_back(cnt);
        }
    }

    // 마지막 시점의 price는 항상 0초간 가격이 떨어지지 않음
    ans.push_back(0);

    return ans;
}

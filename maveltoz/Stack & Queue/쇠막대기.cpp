/*
https://www.welcomekakao.com/learn/courses/30/lessons/42585
*/

#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
    int ans(0);
    vector<int> stick; // 각 막대기의 조각 수

    for(int i=0; i<arrangement.size(); i++){
        // '('가 나왔을 경우
        if(arrangement[i] == '('){
            // 바로 다음에 ')'가 나왔을 경우 (= 레이저가 나왔을 경우)
            if(arrangement[i+1] == ')'){
                // 현재까지 저장된 막대기들 각각의 조각 수에 1을 더함
                for(int j=0; j<stick.size(); j++){
                    stick[j]++;
                }
                // 바로 다음 arrangement[i]는 레이저를 표현하는 '('이므로 i++하여 해당 레이저 다음 인덱스로 이동
                i++;
                continue;
            }
            // 레이저가 아닐 경우 초기 1의 조각 수를 가지는 막대기를 stick에 추가
            stick.push_back(1);
        }
        // ')'가 나왔을 경우
        else{
            // ans에 해당 막대기의 조각 수를 추가
            ans += stick.back();
            // 끝난 막대기를 pop
            stick.pop_back();
        }
    }

    return ans;
}

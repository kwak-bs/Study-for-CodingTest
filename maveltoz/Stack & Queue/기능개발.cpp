/*
https://www.welcomekakao.com/learn/courses/30/lessons/42586
*/

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;

    while(!progresses.empty()) {
        // 각 작업진도에 작업속도를 더함
        for(int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        if(progresses[0] >= 100) {
            int cnt(1); // 배포되는 작업 수를 저장

            // 진도가 100 미만인 작업이 나올때까지, 진도가 100 이상인 작업 수 계산
            for(int i = 1; i < progresses.size(); i++) {
                if(progresses[i] >= 100) cnt++;
                else break;
            }

            // 배포될 작업들의 작업진도와 작업속도를 각 vector에서 지움
            for(int i = 0; i < cnt; i++) {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
            }

            ans.push_back(cnt);
        }
    }

    return ans;
}

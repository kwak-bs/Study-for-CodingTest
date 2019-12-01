/*
https://www.welcomekakao.com/learn/courses/30/lessons/42583
*/

#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // ans : 걸린 시간, bridge_weight : 현재 다리에 있는 트럭들의 총 무게, cnt : 다리를 못 지난 트럭 수
    int ans(1), bridge_weight(0), cnt(truck_weights.size());
    // bridge : 현재 다리에 있는 트럭들<무게, 건넌 길이>
    vector<pair<int, int>> bridge;

    while(1){
        // 걸린시간++
        ans++;
        
        // 다리에 진입하지 못한 트럭이 있을 경우
        if(!truck_weights.empty()){
            // 현재 다리에 있는 트럭들의 총 무게에 진입할 트럭의 무게를 더해도 다리가 견딜 수 있는 무게를 넘지 않을 경우
            if(bridge_weight + truck_weights[0] <= weight){
                // 현재 다리에 있는 트럭들의 총 무게에 진입할 트럭의 무게를 더함
                bridge_weight += truck_weights[0];
                // 현재 다리에 있는 트럭들에 진입할 트럭<무게, 건넌 길이(=0)>을 추가함
                bridge.push_back({truck_weights[0], 0});
                // 다리에 진입하지 못한 트럭들에서 다리에 진입한 트럭을 없앰
                truck_weights.erase(truck_weights.begin());
            }
        }

        // 다리에 있는 트럭들의 건넌 길이를 1씩 더해줌
        for(int i=0; i<bridge.size(); i++){
            bridge[i].second++;
        }

        // 다리의 맨 앞에 있는 트럭의 건넌 길이가 다리 길이와 같을 경우 (= 다리를 다 건넜을 경우)
        if(bridge[0].second >= bridge_length){
            // 현재 다리에 있는 트럭들의 총 무게에서 다리를 다 건넌 트럭의 무게를 뺌
            bridge_weight -= bridge[0].first;
            // 현재 다리에 있는 트럭들에서 다리를 다 건넌 트럭을 뺌
            bridge.erase(bridge.begin());
            // 다리를 못 지난 트럭 수에서 1을 뺌
            cnt--;
        }

        // 다리를 못 지난 트럭이 없을 경우 break
        if(cnt==0) break;
    }

    return ans;
}

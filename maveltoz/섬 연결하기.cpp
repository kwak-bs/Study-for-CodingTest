#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> disjointSet;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int unionFind(int node) {
    if (node == disjointSet[node]) return node; // 부모가 자기자신이면 자기자신 return
    else return disjointSet[node] = unionFind(disjointSet[node]); // 부모가 자기자신이 아니면 부모찾을때까지 재귀
}

int solution(int n, vector<vector<int>> costs) {
    int ans(0);

    disjointSet.resize(n);
    for (int i = 0; i < n; i++) {
        disjointSet[i] = i; // 초기 각 인덱스의 부모는 자기자신
    }
    sort(costs.begin(), costs.end(), compare); // 비용을 기준으로 오름차순으로 sort

    for (int i = 0; i < costs.size(); i++) {
        int start = unionFind(costs[i][0]); // unionFind(시작점)
        int end = unionFind(costs[i][1]); // unionFind(끝점)
        int cost = costs[i][2]; // 비용

        if (start != end) { // 서로 부모가 같지 않으면( = 연결되어 있지 않다는 의미)
            disjointSet[start] = end; // start의 부모를 end로 설정 ( = start와 end가 연결)
            ans += cost;
        }
    }

    return ans;
}

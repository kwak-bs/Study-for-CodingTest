#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> disjointSet;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int unionFind(int node) {
    if (node == disjointSet[node]) return node;
    else return disjointSet[node] = unionFind(disjointSet[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int ans(0);

    disjointSet.resize(n);
    for (int i = 0; i < n; i++) {
        disjointSet[i] = i;
    }
    sort(costs.begin(), costs.end(), compare);

    for (int i = 0; i < costs.size(); i++) {
        int start = unionFind(costs[i][0]);
        int end = unionFind(costs[i][1]);
        int cost = costs[i][2];

        if (start != end) {
            disjointSet[start] = end;
            ans += cost;
        }
    }

    return ans;
}

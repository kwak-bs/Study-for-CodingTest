#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100];

bool cmp_cost(vector<int> v1, vector<int> v2) {
	return v1[2] < v2[2];
}

int find(int u) {
	if (u == parent[u])
		return u;
	return
		parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return false;	// 사이클 방지
	parent[v] = u;
	return true;
}

int solution(int n, vector<vector<int>> costs) {
	int ans = 0, go = 0, to = 0;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	sort(costs.begin(), costs.end(), cmp_cost);

	// least cost node
	ans += costs[0][2];
	go = costs[0][0];
	to = costs[0][1];

	// error
	if (!merge(go, to))
		exit(0);

	// next least cost node
	for (int i = 1; i < costs.size(); i++) {
		go = costs[i][0];
		to = costs[i][1];
		if (!merge(go, to))
			continue;
		ans += costs[i][2];
	}

	return ans;
}

int main() {
	vector<vector<int>> costs = { {0,1,1}, {0,2,2}, {2,3,1} };
	cout << solution(4, costs);
	return 0;
}
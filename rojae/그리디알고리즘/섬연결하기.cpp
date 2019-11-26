#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100];

// cost를 기준으로 오름차순 정렬
bool cmp_cost(vector<int> v1, vector<int> v2) {
	return v1[2] < v2[2];
}

// 부모를 찾아라, 부모를 찾은 경우 자기 자신을 반환한다.
int find(int u) {
	if (u == parent[u])
		return u;
	return
		parent[u] = find(parent[u]);
}

// 노드를 서로 연결한다. 
// u의 부모를 찾는다.
// v의 부모를 찾는다.
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	
	// 부모가 같다면 => 사이클이 생성된다 => false
	if (u == v)
		return false;	// »çÀÌÅ¬ ¹æÁö
	
	// 부모가 다르다면 => v의 부모는 u이다.
	parent[v] = u;
	return true;
}


int solution(int n, vector<vector<int>> costs) {
	int ans = 0, go = 0, to = 0;

	// parent 배열을 생성하여 자기 자신으로 초기화
	// 자기 자신을 가지는 index는
	// 부모가 자기 자신이다.
	for (int i = 0; i < n; i++)
		parent[i] = i;

	// cost를 기준으로 오름차순 정렬
	sort(costs.begin(), costs.end(), cmp_cost);

	// least cost node
	ans += costs[0][2];	// ans += least cost
	go = costs[0][0];	// go : 어디에서
	to = costs[0][1];	// to : 어디로 향한다.

	// least cost의 노드가 자기 자신을 부모로 가진다.
	// error	
	if (!merge(go, to))
		exit(0);

	// next least cost node
	// 다음으로 작은 비용을 가지는 노드
	for (int i = 1; i < costs.size(); i++) {
		go = costs[i][0];	// go : 어디에서
		to = costs[i][1];	// to : 어디로 향한다.
		if (!merge(go, to))	// 사이클이 있는 경우
			continue;
		else				// 사이클이 없는 경우
			ans += costs[i][2];	// ans += least cost
 	}
	return ans;
}

int main() {
	vector<vector<int>> costs = { {0,1,1}, {0,2,2}, {2,3,1} };
	cout << solution(4, costs);
	return 0;
}

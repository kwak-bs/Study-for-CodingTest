/*
https://programmers.co.kr/learn/courses/30/lessons/42861
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
vector<vector<int>> costs;
vector<int> disjointSet;

void inputData() {
	cin >> n;
	cin.get();
	cin.get();

	while (1) {
		char c;
		vector<int> tmp(3);
		cin.get();
		cin >> tmp[0];
		cin.get();
		cin >> tmp[1];
		cin.get();
		cin >> tmp[2];
		cin.get();
		costs.push_back(tmp);
		cin >> c;
		if (c == ']') break;
	}
}

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int unionFind(int node) {
	if (node == disjointSet[node]) return node;
	else return disjointSet[node] = unionFind(disjointSet[node]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();

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

	cout << ans;

	return 0;
}

/*
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
*/

/*
<Kruskal Algorithm>
https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html
*/

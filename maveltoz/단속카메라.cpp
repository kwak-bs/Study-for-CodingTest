/*
https://programmers.co.kr/learn/courses/30/lessons/42884
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int flag(-30001), ans;
vector<vector<int>> routes;

void inputData() {
	vector<int> start_end(2);
	char c;
	cin.get();
	while (1) {
		cin.get();
		cin >> start_end[0];
		cin.get();
		cin >> start_end[1];
		routes.push_back(start_end);
		cin.get();
		cin >> c;
		if (c == ']') break;
		cin.get();
	}
}

bool compare(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();

	sort(routes.begin(), routes.end(), compare);

	for (int i = 0; i < routes.size(); i++) {
		if (flag < routes[i][0]) {
			flag = routes[i][1];
			ans++;
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

bool compare(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
	int flag(-30001), ans(0);

	sort(routes.begin(), routes.end(), compare);

	for (int i = 0; i < routes.size(); i++) {
		if (flag < routes[i][0]) {
			flag = routes[i][1];
			ans++;
		}
	}

	return ans;
}
*/

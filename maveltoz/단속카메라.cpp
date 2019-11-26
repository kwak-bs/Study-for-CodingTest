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

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
	int ans(0);

	sort(weight.begin(), weight.end());

	if (weight[0] > 1) {
		ans = 1;
		return ans;
	}

	for (int i = 0; i < weight.size(); i++) {
		ans += weight[i];
		if (i != weight.size() - 1 && ans + 1 < weight[i + 1]) break;
	}

	return ++ans;
}

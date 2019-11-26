/*
https://programmers.co.kr/learn/courses/30/lessons/42886
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans;
vector<int> weight;

void inputData() {
	cin.get();
	while (1) {
		int k;
		char c;
		cin >> k;
		weight.push_back(k);
		cin >> c;
		if (c == ']') break;
		cin.get();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();

	sort(weight.begin(), weight.end());

	if (weight[0] > 1) {
		cout << 1;
		exit(0);
	}

	for (int i = 0; i < weight.size(); i++) {
		ans += weight[i];
		if (i != weight.size() - 1 && ans + 1 < weight[i + 1]) break;
	}

	cout << ++ans;

	return 0;
}

/*
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
*/

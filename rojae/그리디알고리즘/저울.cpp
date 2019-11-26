/*
 * problem site : https://programmers.co.kr/learn/courses/30/lessons/42886
 * maveltoz code : https://github.com/kwak-bs/Study-for-CodingTest/blob/master/maveltoz/%EC%A0%80%EC%9A%B8.cpp
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int ans = 0;

	sort(weight.begin(), weight.end());

	if (weight[0] > 1)
		return 1;

	for(int i = 0; i < weight.size(); i++) {
		ans += weight[i];
		if (ans + 1 < weight[i + 1] && i != weight.size())
			break;
	}

	return ans + 1;
}

int main() {
	vector<int> weight = { 3,1,6,2,7,30,1 };
	cout << solution(weight);
	return 0;
}

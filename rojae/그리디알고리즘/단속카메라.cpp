/*
 * https://programmers.co.kr/learn/courses/30/lessons/42884
 */


// 역주행은 없기 때문에 sort를 해주어
// end point를 기점으로 값을 검사

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int start = -999999999;
int ans = 0;

bool cmp_second(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}

// end point sort 이후에
// 시작 지점을 변경해주면서 검사
int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end(), cmp_second);
	for (int i = 0; i < routes.size(); i++) {
		if (start < routes[i][0]) {
			start = routes[i][1];
			ans++;
		}
	}
	return ans;
}

int main() {
	vector<vector<int>> r = { {-20,15} , {-14,-5}, {-18,-13}, {-5,-3} };
	cout << solution(r);
	return 0;
}
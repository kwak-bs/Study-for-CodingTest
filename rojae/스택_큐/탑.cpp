#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> ans;
	
	for (int i = heights.size() - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			// 앞에 있는 숫자가 보다 작은 경우
			if (heights[j] > heights[i]) {
				ans.push_back(j+1);
				break;
			}
			else if (j == 0)
				ans.push_back(0);
		}
	}
	ans.push_back(0);

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	//5,4,2,6,1,3,4,9,5
	vector<int> h = { 3,9,9,3,5,7,2 };
	vector<int> ans;
	
	ans = solution(h);

	for (int i : ans)
		cout << i;

	return 0;
}
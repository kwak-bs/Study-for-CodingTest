#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	
	for (int i = 0; i < commands.size(); i++) {
		int start = commands[i][0];
		int end = commands[i][1];
		int k = commands[i][2];

		vector<int> tmp(end - start + 1);

		copy(array.begin() + start - 1, array.begin() + end, tmp.begin());
		
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[k-1]);
	}
	return answer;
}

int main() {
	vector<int> a = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> c = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
	vector<int> ans;

	ans = solution(a, c);
	
	for (int i : ans)
		cout << i;

	return 0;
 }
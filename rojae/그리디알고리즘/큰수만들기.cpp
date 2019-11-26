/*
 * https://programmers.co.kr/learn/courses/30/lessons/42883
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string solution(string number, int k) {
	int n = number.size();
	k = n - k;
	string ans;

	// Maximum value, least k from last index

	int max_idx = -1;
	for (int flag = 0; flag < k; flag++) {
		int cur_max = 0;
		for (int i = max_idx + 1; i <= n - k + flag; i++) {
			int value = number[i];
			if (cur_max < value) {
				cur_max = value;
				max_idx = i;
				if (value == '9')	
					break;
			}
		}
		ans += to_string(cur_max - '0');
	}

	return ans;
}

int main() {
	string number;
	int k;

	cin >> number >> k;
	cout << solution(number, k);
	
	return 0;
}


/*
 * https://programmers.co.kr/learn/courses/30/lessons/42860 
 */

// case 11 error

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int solution(string name) {
	int ans = 0;
	int n = name.size();
	string s;				// fill only 'A' {A0,A1, ... An}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 26; j++) {
			char c1 = name[i] - j;
			char c2 = name[i] + j;
			if (c1 < 'A')
				c1 = 'Z';
			if (c2 > 'Z')
				c2 = 'A';
			if (c1 == 'A' || c2 == 'A') {
				ans += j;
				break;
			}
		}
		s += 'A';
	}

	string left_s = name;
	string right_s = name;
	left_s[0] = right_s[0] = 'A';

	for (int i = 1; i < n; i++) {
		if (right_s[i] != s[i])
			right_s[i] = s[i];
		if (left_s[n - i] != s[n - i])
			left_s[n - i] = s[n - i];
		if (left_s == s || right_s == s) {
			ans += i;
			break;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string word;

	cin >> word;

	cout << solution(word);

	return 0;
}
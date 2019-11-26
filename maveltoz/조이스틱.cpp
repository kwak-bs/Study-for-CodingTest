/*
https://programmers.co.kr/learn/courses/30/lessons/42860
*/

#include <iostream>
#include <string>
using namespace std;

int now, r_cnt, l_cnt, ans;
string s, s_complete("");

int alphaGap(char c) {
	int gap(0);
	if ('A' <= c && c <= 'N') {
		gap = c - 'A';
	}
	else {
		gap = 'A' + 26 - c;
	}
	return gap;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		s_complete += 'A';
	}

	if (s == s_complete) {
		cout << "0";
		exit(0);
	}

	ans += alphaGap(s[0]);
	s[0] = 'A';

	while (1) {
		int tmp = now + 1;
		r_cnt = 0;
		l_cnt = 0;
		if (s == s_complete) break;

		for (int i = 0; i < s.size(); i++) {
			r_cnt++;
			if (tmp >= s.size()) tmp = 0;
			if (s[tmp++] != 'A') break;
		}
		tmp = now - 1;
		for (int i = 0; i < s.size(); i++) {
			l_cnt++;
			if (tmp <= 0) tmp = s.size() - 1;
			if (s[tmp--] != 'A') break;
		}

		if (r_cnt <= l_cnt) {
			tmp = now + r_cnt < s.size() ? now + r_cnt : now + r_cnt - s.size();
			ans += alphaGap(s[tmp]);
			s[tmp] = 'A';
			ans += r_cnt;
			now = tmp;
		}
		else {
			tmp = now - l_cnt >= 0 ? now - l_cnt : now - l_cnt + s.size();
			ans += alphaGap(s[tmp]);
			s[tmp] = 'A';
			ans += l_cnt;
			now = tmp;
		}
	}

	cout << ans;

	return 0;
}

/*
#include <string>
#include <vector>
using namespace std;

int alphaGap(char c) {
	int gap(0);
	if ('A' <= c && c <= 'N') {
		gap = c - 'A';
	}
	else {
		gap = 'A' + 26 - c;
	}

	return gap;
}

int solution(string s) {
	int now(0), r_cnt(0), l_cnt(0), ans(0);
	string s_complete("");

	for (int i = 0; i < s.size(); i++) {
		s_complete += 'A';
	}

	if (s == s_complete) {
		return ans;
	}

	ans += alphaGap(s[0]);
	s[0] = 'A';

	while (1) {
		int tmp = now + 1;
		r_cnt = 0;
		l_cnt = 0;
		if (s == s_complete) break;

		for (int i = 0; i < s.size(); i++) {
			r_cnt++;
			if (tmp >= s.size()) tmp = 0;
			if (s[tmp++] != 'A') break;
		}
		tmp = now - 1;
		for (int i = 0; i < s.size(); i++) {
			l_cnt++;
			if (tmp <= 0) tmp = s.size() - 1;
			if (s[tmp--] != 'A') break;
		}

		if (r_cnt <= l_cnt) {
			tmp = now + r_cnt < s.size() ? now + r_cnt : now + r_cnt - s.size();
			ans += alphaGap(s[tmp]);
			s[tmp] = 'A';
			ans += r_cnt;
			now = tmp;
		}
		else {
			tmp = now - l_cnt >= 0 ? now - l_cnt : now - l_cnt + s.size();
			ans += alphaGap(s[tmp]);
			s[tmp] = 'A';
			ans += l_cnt;
			now = tmp;
		}
	}

	return ans;
}
*/

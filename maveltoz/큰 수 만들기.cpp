/*
https://programmers.co.kr/learn/courses/30/lessons/42883
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string number, ans("");
int k, len, max_number(-1), index(-1);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> number >> k;
	len = number.size() - k;

	for (int i = k; i < number.size(); i++) {
		max_number = -1;
		for (int j = index + 1; j <= i; j++) {
			if (number[j] > max_number) {
				max_number = number[j];
				index = j;
			}
		}
		ans += number[index];
		number[index] = 0;
	}

	cout << ans;

	return 0;
}

/*
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string ans = "";
	int len = number.size() - k;
	int max_number(-1), index(-1);

	for (int i = k; i < number.size(); i++) {
		max_number = -1;
		for (int j = index + 1; j <= i; j++) {
			if (number[j] > max_number) {
				max_number = number[j];
				index = j;
			}
		}
		ans += number[index];
		number[index] = 0;
	}

	return ans;
}
*/

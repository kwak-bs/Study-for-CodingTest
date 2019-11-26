/*
https://programmers.co.kr/learn/courses/30/lessons/4286
*/

#include <iostream>
#include <vector>
using namespace std;

int N, ans;
vector<int> lost;
vector<int> reserve;

void inputData() {
	bool lr = true;
	cin >> N;
	cin.get();
	while (1) {
		char c;
		cin >> c;
		if (c == '[' || c == ',') continue;
		if (c == ']') {
			if (lr) {
				lr = false;
				cin.get();
				continue;
			}
			break;
		}
		if (lr) lost.push_back(c - '0');
		else reserve.push_back(c - '0');
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();

	ans = N - lost.size();

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost[i] = -1;
				reserve[j] = -1;
				ans++;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		int before = lost[i] - 1;
		int after = lost[i] + 1;

		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == before || reserve[j] == after) {
				reserve[j] = -1;
				ans++;
				break;
			}
		}
	}

	cout << ans;
	
	return 0;
}

/*
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int ans = n - lost.size();

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost[i] = -1;
				reserve[j] = -1;
				ans++;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		int before = lost[i] - 1;
		int after = lost[i] + 1;

		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == before || reserve[j] == after) {
				reserve[j] = -1;
				ans++;
				break;
			}
		}
	}

	return ans;
}
*/

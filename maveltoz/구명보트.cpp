/*
https://programmers.co.kr/learn/courses/30/lessons/42885
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> people;
int limit, flag, ans;

void inputData() {
	cin.get();
	while (1) {
		int weight;
		cin >> weight;
		people.push_back(weight);
		char c;
		cin >> c;
		if (c == ']') break;
	}
	cin >> limit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();

	sort(people.begin(), people.end());

	for (int i = people.size() - 1; i >= flag; i--) {
		if (people[flag] + people[i] <= limit) {
			flag++;
		}
		ans++;
	}

	cout << ans;

	return 0;
}

/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int flag(0), ans(0);

	sort(people.begin(), people.end());

	for (int i = people.size() - 1; i >= flag; i--) {
		if (people[flag] + people[i] <= limit) {
			flag++;
		}
		ans++;
	}

	return ans;
}
*/

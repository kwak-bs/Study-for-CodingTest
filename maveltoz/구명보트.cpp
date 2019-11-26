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

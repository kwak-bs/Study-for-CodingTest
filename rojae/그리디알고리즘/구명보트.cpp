// https://programmers.co.kr/learn/courses/30/lessons/42885

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<int> people = { 70,80,50 };
int limit(100);

int solution(vector<int> people, int limit) {
	int heavy_people;
	int n(people.size());
	int j = people.size() - 1;
	int ans = n;

	sort(people.begin(), people.end());

	for (int i = 0; j > i; j--) {
		heavy_people = people[j];
		if (people[i] + heavy_people <= limit) {
			ans--;
			i++;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cout << solution(people, limit);
	return 0;
}
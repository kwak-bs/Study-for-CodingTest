/*
 * https://programmers.co.kr/learn/courses/30/lessons/42862 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int student[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	for (int i : reserve) 
		student[i] += 1;

	for (int i : lost) 
		student[i] += -1;

	for (int i = 1; i <= n; i++) {
		if (student[i] == -1) {
			if (student[i - 1] == 1)
				student[i - 1] = student[i] = 0;
			else if (student[i + 1] == 1)
				student[i] = student[i + 1] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (student[i] != -1) 
			answer++;

	return answer;
}



int main() {
	// cpp speed up
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> lost = { 1,2,3,4,5};
	vector<int> reserve = { 1,2,3,4,5 };

	cout << solution(n, lost, reserve);
	return 0;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
	int size = prices.size();
	vector<int> answer(size);

	answer[size - 1] = 0;

	for (int i = size - 2; i >= 0; i--) {
		int curPrice = prices[i];
		
		if (curPrice > prices[i + 1]) {
			answer[i] = 1;
			continue;
		}

		int checkPrice = answer[i + 1] + 1 + i;
		while (checkPrice < (size - 1) && curPrice <= prices[checkPrice]) {
			checkPrice += answer[checkPrice];
		}
		answer[i] = checkPrice - i;

	}
	
	return answer;
}

int main() {
	vector<int> p = { 1,2,3,2,3 };
	vector<int> ans;
	
	ans = solution(p);

	for (int i : ans)
		cout << i;

	return 0;
}
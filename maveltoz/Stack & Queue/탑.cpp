/*
https://www.welcomekakao.com/learn/courses/30/lessons/42588
*/

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> ans(heights.size(), 0);

    for (int i = heights.size() - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (heights[i] < heights[j]) {
                ans[i] = j + 1;
                break;
            }
        }
    }

    return ans;
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> heights;
vector<int> ans;

void inputData() {
	string input;
	getline(cin, input);
	for (char c : input) {
		if (c != '[' && c != ',' && c != ']') {
			heights.push_back(c - '0');
		}
	}
}

void outputData() {
	cout << "[";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << ",";
	}
	cout << "]";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();
  
	ans.resize(heights.size(), 0);

	for (int i = heights.size() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				ans[i] = j + 1;
				break;
			}
		}
	}

	outputData();

	return 0;
}
*/

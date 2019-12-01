/*
https://www.welcomekakao.com/learn/courses/30/lessons/42587
*/

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> input, int location) {
    int ans = 0;
    vector<pair<int, int>> priorities;
    
    // priorities에 pair<중요도, 초기순서>를 저장
    for(int i = 0; i < input.size(); i++) {
        priorities.push_back({input[i], i});
    }
    
    while (!priorities.empty()) {
      // now에 대기목록 맨 앞의 pair<중요도, 초기순서>를 저장
      pair<int, int> now = priorities[0];
      
      for (pair<int, int> check : priorities) {
        //now의 중요도보다 큰 중요도를 가진 작업이 있는 경우
        if (now.first < check.first) {
          //now를 대기목록 맨 뒤로 이동
          priorities.push_back(now);
          priorities.erase(priorities.begin());
          break;
          }
          
        //now의 중요도가 가장 큰 경우
        if (check == priorities.back()) {
          //now의 초기순서와 location이 같을 경우 
          if (now.second == location) {
            return ++ans;
            }
            
          //now의 초기순서와 location이 다를 경우
          priorities.erase(priorities.begin());
          ans++;
          }
       }
   }
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int location, ans;
vector<int> input;
vector<pair<int, int>> priorities;

void inputData() {
	string s;
	getline(cin, s);
	for (char c : s) {
		if (c != '[' && c != ',' && c != ']' && c != ' ') {
			input.push_back(c - '0');
		}
	}
	cin >> location;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	inputData();

	for (int i = 0; i < input.size(); i++) {
		priorities.push_back({ input[i], i });
	}

	while (!priorities.empty()) {
		pair<int, int> now = priorities[0];

		for (pair<int, int> check : priorities) {
			if (now.first < check.first) {
				priorities.push_back(now);
				priorities.erase(priorities.begin());
				break;
			}

			if (check == priorities.back()) {
				if (now.second == location) {
					cout << ++ans;
					return 0;
				}
        
				priorities.erase(priorities.begin());
				ans++;
			}
		}
	}

	return 0;
}
*/

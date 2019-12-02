#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string str) {
	int str_size = str.size();
	int ans = 0;

	stack<int> st;
	for (int i = 0; i < str_size; i++) {
		if (str[i] == '(')
			st.push(i);
		else {
			// 이전에 '('이 들어왔다. 
			// 레이저인 경우
			if (st.top() == i - 1) {
				st.pop();
				ans += st.size();	// stack은 현재 막대기의 갯수를 size로 가지고 있다.
			}
			// 레이저가 아닌 조각인 경우
			// 닫는 조각이다.
			else {
				ans += 1;
				st.pop();
			}
		}
	}

	return ans;
}

int main() {
	string stick = "()(((()())(())()))(())";
	cout << solution(stick);
	return 0;
}
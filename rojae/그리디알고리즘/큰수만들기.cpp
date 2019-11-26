/*
 * https://programmers.co.kr/learn/courses/30/lessons/42883
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string solution(string number, int k) {
	int n = number.size();
	k = n - k;			// k 재정의 사용할 수 있는 수의 갯수
	string ans;			// 정답 string

	// Maximum value, least k from last index
	int max_idx = -1;
	
	// flag는 자리수를 의미한다
	// flag 0은 가장 큰 자리 수
	for (int flag = 0; flag < k; flag++) {	
		int cur_max = 0;
		
		// max_idx : 직전에 처리한 숫자의 위치
		// i는 직전에 처리한 수보다 뒤에 위치하게 된다.
		// n - k + flag : 1092에서 2개의 숫자를 추출할 경우
		// 		: 최대 값인 9는 뒤에 숫자가 최소 하나가 있어야한다
		for (int i = max_idx + 1; i <= n - k + flag; i++) {
			int value = number[i];
			if (cur_max < value) {
				cur_max = value;
				max_idx = i;
				
				// 효율성 문제 해결
				if (value == '9')	
					break;
			}
		}
		// 아스키코드를 숫자로 바꾼다
		ans += to_string(cur_max - '0');
	}

	return ans;
}

int main() {
	string number;
	int k;

	cin >> number >> k;
	cout << solution(number, k);
	
	return 0;
}


#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int size = progresses.size();
	int cnt = 0;

	// progresses를 남은 퍼센트로 재정의해준다.
	for (int i = 0; i < size; i++)
		progresses[i] = 100 - progresses[i];

	// progresses를 몇 일이 남았는지 재정의해준다.
	for (int i = 0; i < size; i++) {
		int tmp = progresses[i] / speeds[i];
		if ((progresses[i] % speeds[i]) > 0)
			tmp++;
		progresses[i] = tmp;
	}

	// 내림차순의 시작
	int max = progresses[0];

	// 내림차순 정렬이 얼마나 있는 지 검사하는 코드
	// 7 3 9 => 2, 1
	for (int i = 1; i < size; i++) {
		if (max < progresses[i]) {
			max = progresses[i];
			answer.push_back(cnt+1);
			cnt = 0;
		}
		else {
			cnt++;
		}
		
		// 마지막은 무조건 출력을 해야한다.
		if (i == size - 1)
			answer.push_back(cnt + 1);
	}

	return answer;
}

int main() {
	vector<int> p = { 93,30,55 };
	vector<int> s = { 1,30,5 };
	vector<int> ans;

	ans = solution(p, s);
	
	for (int i : ans)
		cout << i;

	return 0;
}
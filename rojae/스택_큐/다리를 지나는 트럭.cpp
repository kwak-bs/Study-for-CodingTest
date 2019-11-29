#include <string>
#include <vector>
#include <iostream>

using namespace std;

// v의 두번째 요소를 모두 -1 해준다.
void updateTime(vector<pair<int,int>> &v) {
	for (int i = 0; i < v.size(); i++)
		v[i].second--;
}

// v의 두번째 요소가 0인 곳을 찾아
// 즉 도착한 화물을 찾아
// 다리가 견딜 수 있는 무게를 갱신시키고
// 어디까지 도착했는지 인덱스를 반환한다.
int arrive(vector<pair<int, int>> &v, int &sum) {
	int idx;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 0) {
			sum -= v[i].first;
			idx = i;
		}
		else
			return idx + 1;
	}
	return idx + 1;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	// answer는 최소 1이다.
	// moving은 어디까지 처리하는지
	// remain은 다리가 더 버틸 수 있는 무게
	// sum은 현재 다리가 버티고 있는 무게
	int answer = 1, moving = 0;
	int remain = 0, sum = 0;
	
	// 현재 운반하고 있는 화물들로 <무게, 남은시간>을 가진다.
	vector<pair<int, int>> trucking;

	// 첫 번째 화물을 넣어준다.
	trucking.push_back({ truck_weights[0], bridge_length });
	sum += truck_weights[0];

	// 운반하는 화물이 없을 때까지
	while (!trucking.empty()) {
		updateTime(trucking);		// 남은 시간을 -1 해준다.
		answer++;					// 걸린 시간을 +1 해준다.

		// 도착한 화물이 있는 경우
		// arrive를 통해서 반환된 인덱스까지 삭제한다.
		if (trucking[0].second == 0)
			trucking.erase(trucking.begin(), trucking.begin() + arrive(trucking, sum));
		
		// 도착한 화물에 의한
		// 다리가 더 버틸 수 있는 무게 갱신
		remain = weight - sum;

		// 더 이상 도착할 화물이 있다면
		if (moving + 1 < truck_weights.size()) {
			// 그리고 그 무게를 다리가 버틸 수 있다면
			if (remain >= truck_weights[moving + 1]) {
				// 운반하는 화물 리스트에 넣어준다.
				// 다리가 버티고 있는 무게를 갱신한다.
				trucking.push_back({ truck_weights[++moving], bridge_length });
				sum += truck_weights[moving];
			}
		}
	}

	return answer;
}

int main() {
	int b = 100;
	int w = 100;
	vector<int> v = { 10,10,10,10,10,10,10,10,10,10 };
	cout << solution(b, w, v);
	return 0;
}
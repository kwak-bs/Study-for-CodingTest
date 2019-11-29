#include<iostream>
#include<vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	vector<pair<int, int>> p;
	int ans = 0, i = 0, location_value;

	for (int i = 0; i < priorities.size(); i++)
		p.push_back({ priorities[i], i });

	location_value = priorities[location];

	while (!p.empty()) {
		int max = 0 ,max_idx = 0;
		
		// 최대 값과 그것을 담고 있는 인덱스를 저장
		// 1111과 같이 모든 값이 같은 경우
		// 0과 비교하여 첫번째 값과 인덱스가 저장된다.
		for (int i = 0; i < p.size(); i++) {
			if (max < p[i].first) {
				max = p[i].first;
				max_idx = p[i].second;
			}
		}

		// 만약에 찾고자 하는 위치라면
		// 현재의 +1 번째이기 때문에
		// return ans + 1
		if (max_idx == location)
			return ans + 1;
		
		// tmp는 얼마나 우선 순위를 뒤로 미뤄둬야 하는가
		// 11911의 경우 tmp는 2이다.
		int tmp = 0;
		
		// tmp까지의 값과 인덱스를 뒤로 넣어준다.
		// 11911 => 1191111
		for (int i = 0; p[i].second != max_idx; i++) {
			tmp++;
			p.push_back({ p[i].first, p[i].second });
		}

		// 11911의 경우 9끼지 지워야하기 때문에
		// tmp + 1
		// 1191111 => 1111
		p.erase(p.begin(), p.begin() + tmp + 1);
		ans++;
	}
}

int main() {
	vector<int> pri = { 2, 1, 3, 2 };
	int location = 2;

	int ans;
	
	ans = solution(pri, location);
	cout << ans;

	return 0;
}

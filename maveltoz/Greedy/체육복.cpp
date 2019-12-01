#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int ans = n - lost.size();

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost[i] = -1;
				reserve[j] = -1;
				ans++;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		int before = lost[i] - 1;
		int after = lost[i] + 1;

		for (int j = 0; j < reserve.size(); j++) {
			if (reserve[j] == before || reserve[j] == after) {
				reserve[j] = -1;
				ans++;
				break;
			}
		}
	}

	return ans;
}

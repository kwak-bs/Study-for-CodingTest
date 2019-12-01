#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string ans = "";
	int len = number.size() - k;
	int max_number(-1), index(-1);

	for (int i = k; i < number.size(); i++) {
		max_number = -1;
		for (int j = index + 1; j <= i; j++) {
			if (number[j] > max_number) {
				max_number = number[j];
				index = j;
			}
		}
		ans += number[index];
		number[index] = 0;
	}

	return ans;
}

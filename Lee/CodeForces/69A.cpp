#include <iostream> 
#include <cstring>
using namespace std;

int main(void)
{
	int test_case;
	int T;

	cin>>T;
	cin.clear(); 
	cin.ignore(256, '\n');

	int sumXYZ[3] = {0, };

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int xyz[3];
		for(int i=0; i<3; i++) {
			cin >> xyz[i];
			sumXYZ[i] += xyz[i];
		}
	}

	for(int i=0; i<3; i++) {
		// cout << sumXYZ[i] << endl;
		if(sumXYZ[i] != 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}

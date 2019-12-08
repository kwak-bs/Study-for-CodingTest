#include <iostream> 
#include <cstring>
using namespace std;

int main(void)
{
	int test_case;
	int T;
	int count = 0;

	cin>>T;
	cin.clear(); 
	cin.ignore(256, '\n');

	for(test_case = 1; test_case <= T; ++test_case)
	{
		char cs[5];
		cin.getline(cs, 5);
		cin.clear();

		for(int i=0; i<(signed)strlen(cs); i++) {
			if(cs[i] == '+') {
				count++;
				break;
			}
			else if(cs[i] == '-') {
				count--;
				break;
			}
		}

		

	}

	cout << count << endl;

	return 0;
}

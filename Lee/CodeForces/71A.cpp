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

	for(test_case = 1; test_case <= T; ++test_case)
	{
		char cs[110];
		cin.getline(cs, 110);
		cin.clear();

		if(strlen(cs) <= 10) cout << cs;
		else {
			cout << (char)(cs[0]) << (strlen(cs)-2) << (char)(cs[strlen(cs)-1]);
		}

		cout << endl;

	}

	return 0;
}

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
		int Petya, Vasya, Tonya;
		cin >> Petya >> Vasya >> Tonya;
		
		if(Petya + Vasya + Tonya > 1) count++;

		

	}

	cout << count << endl;
	
	return 0;
}

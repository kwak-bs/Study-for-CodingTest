#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cin.clear(); 
	cin.ignore(256, '\n');

	char cs[n+10];
	cin.getline(cs, n+10);
	cin.clear();

	int i = 1;
	int count = 0;
	while(cs[i]) {
		if(cs[i] == cs[i-1]) {
			count++;
		}
		i++;
	}

	cout << count <<endl;

	return 0;
}
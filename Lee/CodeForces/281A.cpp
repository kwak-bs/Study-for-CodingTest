#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{

	char cs[1010];

	cin.getline(cs, 1010);
	cin.clear();

	cout << (char)toupper(cs[0]);

	int i=1;
	while(cs[i]) {
		cout << (char)cs[i];
		i++;
	}

	cout << endl;

	return 0;
}
#include <iostream> 
#include <ctype.h>
#include <cstring>
using namespace std;

int main(void)
{
	char cs[110];
	char c;
	cin.getline(cs, 110);

	for(int i = 0; i < (signed)strlen(cs); i++) {
		c = cs[i];
		cs[i] = tolower(c);

		if(cs[i] != 'a' && cs[i] != 'o' && cs[i] != 'y' && cs[i] != 'e' && cs[i] != 'u' && cs[i] != 'i' && cs[i] != ' ')
			cout << '.' << cs[i];
	}
	// cout << endl;

	return 0;
	
}

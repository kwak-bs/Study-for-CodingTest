#include <iostream> 
using namespace std;

int main(void)
{
	char code = 0b0000000;
	code++;

	cout << (int)code << endl;

	code += (1 << 3);
	char ncode = ~code;

	char tmp = ncode & code;

	cout << (int)tmp << endl;
	

	return 0;
}
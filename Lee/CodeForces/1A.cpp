#include <iostream> 
#include <cmath>
using namespace std;
 
int main(void)
{
	long double n, m, a;
	cin >> n >> m >> a;

    long double result = ceil(n/a) * ceil(m/a);

    cout << (long long int)result << endl;
    
    return 0;
}

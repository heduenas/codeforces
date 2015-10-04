#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

long long n, k;
long long C[100];

int main()
{
	cin >> n >> k;
	C[0] = 1;
	C[1] = 1;
	C[2] = 2;
	for (int i = 3; i <= n; i ++)
		C[i] = C[i-1] + C[i-2];
		
	for (int i = 0; i < n; i ++)
	{
		if (k <= C[n-i-1])
		{
			cout << i+1 << " ";
		} else 
		{
			cout << i+2 << " " << i + 1 << " ";
			i ++;
			k -= C[n-i];
		}
	}
	
	cout << endl;

	return 0;
}



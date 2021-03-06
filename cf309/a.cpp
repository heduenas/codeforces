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

int k, C[2010];
int PT[2010][2010];

const int mod = 1000000007;

void Triangle()
{
	for (int i = 0; i < 1010; i ++)
		PT[i][0] = PT[i][0] = 1;
	for (int i = 1; i < 1010; i ++)
		for (int j = 1; j < i; j ++)
			PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % mod;	
}

long long ans = 1;

int main()
{
	cin >> k;
	scan(C, 0, k);
	
	Triangle();
	
	for (int i = 0, sum = 0; i < k; i ++)
	{
		sum = sum + C[i];
		ans = (ans * (long long)(PT[sum][C[i]-1])) % mod;
	}
	
	cout << ans << endl;
	
	return 0;
}



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
#include <cassert>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>

#define deb(x) cout << #x << " = " << x << endl;
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

int n;
int C[1100];

int DP[510][510];

int f(int l, int r)
{
	if (l == r)
		return 1;

	if (DP[l][r] == -1)
	{
		DP[l][r] = r-l+1;
		for (int i = l; i < r; i ++)
			DP[l][r] = min(DP[l][r], f(l, i) + f(i+1, r));
			
		if (C[l] == C[r])
		{
			if (r == l + 1)
			{
				DP[l][r] =  min(DP[l][r], 1);
			} 
			else
			{
				DP[l][r] =  min(DP[l][r], f(l+1, r-1));
			}
		}
	}
	return DP[l][r];
}

int main()
{
	cin >> n;
	scan(C, 0, n);
	
	memset(DP, -1, sizeof DP);
	
	cout << f(0, n-1) << endl;

	return 0;
}

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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n, m, k;
long long A[50];
long long C[50][50];

long long DP[1 << 18][19];
long long f(long long mask, int prev, int num)
{
	if(num == 0)
		return 0;
	if (DP[mask][prev] == -1)
	{
		DP[mask][prev] = 0;
		for (long long i = 0; i < n; i ++)
		{	if (mask&bit(i))
				DP[mask][prev] = max(DP[mask][prev], A[i] + C[prev][i] + f(mask - bit(i), i, num-1));
		}
	}
	return DP[mask][prev];
}

int main()
{
	memset(DP, -1, sizeof DP);
	cin >> n >> m >> k;
	scan(A, 0, n);
	
	for (int i = 0; i < k; i ++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		a --; b --;
		C[a][b] = c;
	}
	
	cout << f(bit(n)-1, 18, m) << endl;
	
	
	return 0;
}



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

int t, n, k;
char M[3][210];
int DP[3][210];

bool f(int x, int y)
{
	if (x >= n)
		return 1;
	if (DP[y][x] == -1)
	{
		DP[y][x] = 0;
		if (	(y > 0 and M[y-1][x] == '.' and M[y-1][x+1] == '.' and M[y-1][x+2] == '.' and M[y-1][x+3] == '.' and f(x+3, y-1))
		or	(M[y][x] == '.' and M[y][x+1] == '.' and M[y][x+2] == '.' and M[y][x+3] == '.' and f(x+3, y))
		or	(y < 2 and M[y+1][x] == '.' and M[y+1][x+1] == '.' and M[y+1][x+2] == '.' and M[y+1][x+3] == '.' and f(x+3, y+1))	)
			DP[y][x] = 1;
	}
	return DP[y][x];
}

int main()
{
	cin >> t;
	while (t --)
	{
		cin >> n >> k;
		memset(M, '.', sizeof M);
		cin >> M[0] >> M[1] >> M[2];
		M[0][n] = M[1][n] = M[2][n] = '.';
		assert(M[0][n+1] == '.');
		memset(DP, -1, sizeof DP);
		
		int x, y;
		if (M[0][0] == 's')
		{
			x = 0; y = 0;
		} else if (M[1][0] == 's')
		{
			x = 0; y = 1;
		} else
		{
			x = 0; y = 2;
		}
		
		if (M[y][1] != '.' or !f(1, y))
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
		/*
		print(DP[0], 0, n); cout << endl;
		print(DP[1], 0, n); cout << endl;
		print(DP[2], 0, n); cout << endl;*/
	}
	
	return 0;
}



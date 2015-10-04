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

int n, m, b, mod;
int A[10000];
int DP[2][2000][2000];
int ans;

int main()
{
	cin >> n >> m >> b >> mod;
	scan(A, 0, n);

	DP[0][0][0] = 1;
	for (int idx = 0; idx < n; idx ++)
	{
		memset(DP[(idx+1)%2], 0, sizeof DP[(idx+1)%2]);
		for (int tot = 0; tot <= m; tot ++)
		{
			for (int prod = 0; prod <= b; prod ++)
			{
				//cerr << DP[idx%2][tot][prod] << " ";
				DP[idx%2][tot+1][prod+A[idx]] += DP[idx%2][tot][prod];
				DP[idx%2][tot+1][prod+A[idx]] %= mod;
				DP[(idx+1)%2][tot][prod] +=DP [idx%2][tot][prod];
				DP[(idx+1)%2][tot][prod] %= mod;
			}
			//cerr << endl;
		}
		//cerr << endl << endl;
	}

	for (int i = 0; i <= b; i ++)
	{
		ans += DP[(n-1)%2][m][i];
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}
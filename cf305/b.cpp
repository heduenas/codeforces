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

int n;
int A[200100];
int dp[20][200100];

// RMQ DP
// Range Minimum Query Dynamic Programming

void DP()
{

	for (int j = 0; j < n; j ++)
		dp[0][j] = j;
	
	for (int i = 1; (1 << i) <= n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (A[dp[i-1][j]] > A[dp[i-1][j+(1 << (i-1))]])
				dp[i][j] = dp[i-1][j+(1 << (i-1))];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
}

int query(int l, int r)
{
	int i=0;
	while(l + (1<<(i+1))-1 <= r)
		i++;
	
	if (A[dp[i][l]] < A[dp[i][r-(1<<i)+1]])
		return dp[i][l];
	else
		return dp[i][r-(1<<i)+1];
}

int ans[200100];
int solve(int l, int r)
{
	if (l > r)
		return 0;
	int mini = query(l, r);
	ans[r-l+1] = max(ans[r-l+1], A[mini]);
	solve(l, mini-1);
	solve(mini+1, r);
	return 1;
}

int main()
{
	cin >> n;
	scan(A, 0, n);
	
	DP();
	
	solve(0, n-1);
	
	for (int i = n-1; i >= 1; i --)
	{
		ans[i] = max(ans[i], ans[i+1]);
	}
	
	print(ans, 1, n+1);
			
	return 0;
}



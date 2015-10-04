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

#define par pair<pair<int, int>, int>
#define p1 first.first
#define p2 first.second
#define p3 second

#define eps = 1e-6

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n, m;
par P[200100];
int maxi;
int ans[200100];

int bt[200100];
int bt2[200100];
int verify(int idx)
{
	memset(bt2, 0, sizeof bt2);
	for (int i = 0; i <= n; i ++)
	{
		if (ans[i] & bit(idx))
			bt2[i] ++;
		if (i > 0)
			bt2[i] += bt2[i-1];
	}

	for (int i = 0; i < m; i ++)
	{
		if ((P[i].p3 & bit(idx))
			and ( bt2[P[i].p2-1] == (P[i].p1>1?bt2[P[i].p1-2]:0) ))
			return false;
	}

	return true;
}

int apply(int idx)
{
	memset(bt, 0, sizeof bt);
	for (int i = 0; i < m; i ++)
	{
		if ((P[i].p3 & bit(idx)) == 0) {
			bt[P[i].p1-1] ++;
			bt[P[i].p2] --;
		}
	}

	for (int i = 0, cum = 0; i < n; i ++)
	{
		cum += bt[i];
		if (cum == 0)
			ans[i] |= bit(idx);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i ++)
	{
		cin >> P[i].p1 >> P[i].p2 >> P[i].p3;
		maxi = max(P[i].p3, maxi);
	}

	for (int i = 0; i < 31; i ++)
	{
		if (bit(i) > maxi)
			break;
		apply(i);
		if (!verify(i))
		{
			cout << "NO\n";
			return 0;
		}
	}

	for (int i = 0; i < n; i ++)
	{
		if(ans[i] > maxi)
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	print(ans, 0, n);
	cout << endl;

	return 0;
}



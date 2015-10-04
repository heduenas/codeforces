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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int HPy, HPm, ATKy, ATKm, DEFy, DEFm;
int h, a, d;

int ans;

int k1(int ak)
{
	return (HPm + ak - DEFm - 1) / (ATKy - DEFm);
}

int k2(int ak1, int ak2)
{
	return (ak1 + ATKm - ak2 - 1) / (ATKm - ak2);
}

int cost(int k)
{
	int ret = 0;
	for (int i = 0; i <= 100; i ++)
	{
		if ((HPm + ATKy+i - DEFm - 1) / (ATKy+i - DEFm) <= k)
		{
			ret = i * a;
		}
	}
	
	int opt1 = d * max(0, DEFy - ATKm + 1);
	int opt2 = 0;
	for (int i = 0; i < max(0, DEFy - ATKm); i ++)
	{	
		opt2 = min(opt2, d * i + h * (HPy-ATKm+(DEFy+i)));
	}
	ret += min(opt1, opt2);
	return ret;
}

int main()
{
	cin >> HPy >> ATKy >> DEFy;
	cin >> HPm >> ATKm >> DEFm;
	cin >> h >> a >> d;
	
	ans = a * max(0, DEFm - ATKy + 1);
	ATKy = max(DEFm+1, ATKy);
	
	if (ATKy > DEFy and k1(ATKy) >= k2(HPy, DEFy))
	{
		int mincost = 1 << 30;
		for (int k = k1(ATKy)-1, end = k2(HPy, DEFy); k <= end; k ++)
		{
			mincost = min(mincost, cost(k));
		}
	}
	cout << ans << endl;
	return 0;
}

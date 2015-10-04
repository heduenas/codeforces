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
vector<int> G[200100];

int DP[4][200100];

int f(int mode, int nd, int pnt)
{
	if (DP[mode][nd] == -1)
	{
		DP[mode][nd] = 0;
		
		if (mode == 0)
		{
			int child = 0;
			int mode1 = 0;
			int mode2 = 0;
			for (int i = 0; i < G[nd].size(); i ++)
			{
				if (G[nd][i] == pnt)
					continue;
				child ++;
				mode1 += f(1, G[nd][i], nd);
				mode2 += f(2, G[nd][i], nd);
			}
			if ((mode1 == child) and (mode2 >= child-2))
				DP[mode][nd] = 1;
		}
		if (mode == 1)
		{
			int child = 0;
			int mode1 = 0;
			int mode2 = 0;
			for (int i = 0; i < G[nd].size(); i ++)
			{
				if (G[nd][i] == pnt)
					continue;
				child ++;
				mode1 += f(1, G[nd][i], nd);
				mode2 += f(2, G[nd][i], nd);
			}
			if ((mode1 == child) and (mode2 >= child-1))
				DP[mode][nd] = 1;
		}
		if (mode == 2)
		{
			int child = 0;
			int mode3 = 0;
			for (int i = 0; i < G[nd].size(); i ++)
			{
				if (G[nd][i] == pnt)
					continue;
				child ++;
				mode3 += f(3, G[nd][i], nd);
			}
			if ((mode3 == child) and (child <= 2))
				DP[mode][nd] = 1;
		}
		if (mode == 3)
		{
			int child = 0;
			int mode3 = 0;
			for (int i = 0; i < G[nd].size(); i ++)
			{
				if (G[nd][i] == pnt)
					continue;
				child ++;
				mode3 += f(3, G[nd][i], nd);
			}
			if ((mode3 == child) and (child <= 1))
				DP[mode][nd] = 1;
		}
	}
	return DP[mode][nd];
}

int main()
{
	memset(DP, -1, sizeof DP);
	cin >> n;
	for (int i = 0; i < n-1; i ++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
		if (f(0, 0, 0))
		{
			cout << "Yes" << endl;
			return 0;
		}
		
	cout << "No" << endl;
	
	return 0;
}

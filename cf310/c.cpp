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
#include <iterator>

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

set<par> S;
int n, q;

int main()
{
	cin >> n >> q;
	for (int i = 0; i < q; i ++)
	{
		par nu;
		char dir[2];
		cin >> nu.p1 >> nu.p2 >> dir;
		if (dir[0] == 'U')
			nu.p2 = 0;
		else
			nu.p2 = 1;
		
		par srcp;
		srcp.p1 = nu.p1;
		srcp.p2 = srcp.p3 = 0;
		std::set<par>::iterator it = S.lower_bound(srcp);
		if ((*it).p1 == nu.p1)
		{
			nu.p3 = 0;
		}
		else if (dir[0] == 'U')
		{
			if (it == S.end())
			{
				nu.p3 = n+1-nu.p1;
			} else
			{
				if ((*it).p2 == 0) // UP
				{
					nu.p3 = (*it).p3 + (*it).p1 - nu.p1;
				} 
				else // LEFT
				{
					nu.p3 = (*it).p1 - nu.p1;
				}
			}
		}
		else
		{
			if (it != S.begin())
				--it;
			if ((*it).p1 > nu.p1)
				it = S.end();
			if (it == S.end())
			{
				nu.p3 = nu.p1;
			} else
			{
				if ((*it).p2 == 1) // LEFT
				{
					nu.p3 = (*it).p3 + nu.p1 - (*it).p1;
				} 
				else // UP
				{
					nu.p3 = nu.p1 - (*it).p1;
				}
			}
		}
		
		cout << nu.p3 << endl;
		if (nu.p3 > 0)
			S.insert(nu);
	}
	
	return 0;
}



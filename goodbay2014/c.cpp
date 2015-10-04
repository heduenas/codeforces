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

int n, m;
int w[2010];
int b[2010];

bool done[2010];
int stak[2010], ss;
int ans;
int ans2;

int main()
{
	cin >> n >> m;
	scan(w, 0, n);
	scan(b, 0, m);
	
	for (int i = 0; i < m; i ++)
	{
		if (!done[b[i]])
		{
			stak[ss ++] = b[i];
			done[b[i]] = 1;
		}
	}

	for (int i = 0; i < m; i ++)
	{
		for (int j = 0; j < ss; j ++)
		{
			if (stak[j] == b[i])
			{
				for (int k = j-1; k >= 0; k --)
				{
					ans += w[stak[k]-1];
					swap(stak[k], stak[k+1]);
					//ans2 += w[stak[j]-1];
				}
				break;
			}
		}
	}
	
	cout << ans << endl;
	//cout << ans2 << endl;
	
	return 0;
}



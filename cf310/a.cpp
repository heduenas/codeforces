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

int n, k;
int chain[200100];
int ans;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i ++)
	{
		int m;
		cin >> m;
		scan(chain, 0, m);
		if (chain[0] == 1)
		{
			int ak = 0;
			while(chain[ak] == ak+1)
				ak ++;
			ans += m - ak;
			ans += m - ak;
		}
		else
			ans += 2*m-1;
	}
	
	cout << ans << endl;
	
	return 0;
}



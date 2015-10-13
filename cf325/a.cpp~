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

long long n;
long long V[8100], D[8100], P[8100];
bool u[8100];

void Update(long long idx, long long vol, long long dvol)
{
	if (vol <= 0 or idx >= n)
		return ;
	if (u[idx] == true) {
		Update(idx+1, vol, dvol);
		return ;
	}
	
	P[idx] -= vol;
	if (P[idx] < 0)
	{
		Update(idx+1, vol+dvol, dvol);
		Update(idx+1, D[idx], 0);
		u[idx] = true;
	}
	else
		Update(idx+1, vol+dvol, dvol);
}

vector<long long> ans;

int main()
{
	cin >> n;
	for (long long i = 0; i < n; i ++)
	{
		cin >> V[i] >> D[i] >> P[i];
	}
	
	for (long long i = 0; i < n; i ++)
	{
		if (!u[i])
		{
			Update(i+1, V[i], -1);
			ans.push_back(i+1);
		}
	}
	
	cout << ans.size() << endl;
	print(ans, 0, ans.size());

	return 0;
}



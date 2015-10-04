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

using namespace std;

const int lim =100005;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n, m;
char A[65][65];
bool u[65][65];
bool u2[65][65];
bool v[65][65];

bool win_state(int y0, int x0)
{
	queue<int> Q;
	stack<int> S;
	
	Q.push(y0); Q.push(x0);
	S.push(y0); S.push(x0);
	u[y0][x0] = true;
	
	while (Q.empty() == false)
	{
		int y = Q.front(); Q.pop();
		int x = Q.front(); Q.pop();
		
		for (int i = 0; i < 4; i ++)
		{
			if (	x + dx[i] >= 0
			and	x + dx[i] < m
			and	y + dy[i] >= 0
			and	y + dy[i] < n
			and	u[y + dy[i]][x + dx[i]] == false
			and	A[y + dy[i]][x + dx[i]] == '.'	)
			{
				Q.push(y + dy[i]);
				Q.push(x + dx[i]);
				S.push(y + dy[i]);
				S.push(x + dx[i]);
				u[y + dy[i]][x + dx[i]] = true;
			}
		}
	}
	
	while (!S.empty())
	{
		int x = S.top(); S.pop();
		int y = S.top(); S.pop();
		u2[y][x] = true;
		
		v[y][x] = false;
		bool any = false;
		for (int i = 0; i < 4; i ++)
		{
			if (	x + dx[i] >= 0
			and	x + dx[i] < m
			and	y + dy[i] >= 0
			and	y + dy[i] < n
			and	u2[y + dy[i]][x + dx[i]] == true	)
			{
				if (v[y + dy[i]][x + dx[i]] == false)
					v[y][x] = true;
				any = true;
			}
		}
		if (!any)
			v[y][x] = true;
	}
	
	return v[y0][x0];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    {
    	cin >> A[i];
    }
    
    rep(i, n)
    {
    	rep(j, n)
    	{
   	    memset(u, 0, sizeof u);
   	    memset(u2, 0, sizeof u2);
    	    if (A[i][j] == '.' and win_state(i, j))
    	    {
    	    	cout << 1 << endl;
    	    	return 0;
    	    }
    	}
    }
    
    cout << 2 << endl;
    return 0;
}



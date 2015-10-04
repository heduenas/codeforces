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

int keep[1010];
int n, m;
char M[1010][1010];
int end[1010][1010];

void check()
{
	end[0][0] = n-1;
	for (int col = 0; col < m; col ++)
	{
		int row_a = 0;
		int row = 0;
		while (row < n)
		{
			while (row <= end[row_a][col])
			{
				if (row-row_a > 0 and M[row][col] < M[row-1][col])
					keep[col] = 1;
				row ++;
			}
			row_a = row;
		}
		
		if (keep[col] == 1)
		{
			rep(i, n)
				end[i][col+1] = end[i][col];
		} else
		{
			row_a = 0;
			row = 0;
			while (row_a < n)
			{
				end[end[row_a][col]][col+1] = end[row_a][col];
				for (row = end[row_a][col] - 1; row >= row_a; row --)
				{
					if (M[row][col] == M[row+1][col])
						end[row][col+1] = end[row+1][col+1];
					else
						end[row][col+1] = row;
				}
				row_a = end[row_a][col]+1;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n)
	{
		scanf("%s", M[i]);
	}
	
	check();
	
	int ans = 0;
	rep(i, m)
	{
		if (keep[i])
			ans ++;
	}
	
	cout << ans << endl;
	
	return 0;
}



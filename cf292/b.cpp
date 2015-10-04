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
char M[2100][2100], ans[2100][2100];
int D[2100][2100];
int total, processed;

queue<int> Q;

void neighbors(int i, int j)
{
	for (int k = 0; k < 4; k ++)
	{
		if (M[i + dy[k]][j + dx[k]] == '.')
		{
			D[i + dy[k]][j + dx[k]] --;
			if (D[i + dy[k]][j + dx[k]] == 1)
				Q.push(i + dy[k]), Q.push(j + dx[k]);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	total = n * m;
	for (int i = 0; i < n; i ++)
	{
		scanf("%s", M[i+1]+1);
		for (int j = 0; j < m; j ++)
		{
			ans[i+1][j+1] = M[i+1][j+1];
			if (M[i+1][j+1] == '*')
				total --;
		}
	}
	
	
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (M[i+1][j+1] == '*')
				continue;
			for (int k = 0; k < 4; k ++)
			{
				D[i+1][j+1] += M[i+1 + dy[k]][j+1 + dx[k]] == '.';
			}
			if (D[i+1][j+1] == 1)
				Q.push(i+1), Q.push(j+1);
		}
	}
	
	while (!Q.empty())
	{
		int i = Q.front() - 1; Q.pop();
		int j = Q.front() - 1; Q.pop();
		if (ans[i+1][j+1] != '.')
			continue;

		for (int k = 0; k < 4; k ++)
		{
			if (ans[i+1 + dy[k]][j+1 + dx[k]] == '.')
			{
				processed += 2;
				neighbors(i+1 + dy[k], j+1 + dx[k]);
					
				if (k == 1)
				{
					ans[i+1][j+1] = 'v';
					ans[i+1 + dy[k]][j+1 + dx[k]] = '^';
				}
				if (k == 0)
				{
					ans[i+1][j+1] = '^';
					ans[i+1 + dy[k]][j+1 + dx[k]] = 'v';
				}
				if (k == 2)
				{
					ans[i+1][j+1] = '<';
					ans[i+1 + dy[k]][j+1 + dx[k]] = '>';
				}
				if (k == 3)
				{
					ans[i+1][j+1] = '>';
					ans[i+1 + dy[k]][j+1 + dx[k]] = '<';
				}
				break;
			}
		}
	}
	
	if (processed != total)
		cout << "Not unique" << endl;
	else
		for (int i = 0; i < n; i ++)
		{
			printf("%s", ans[i+1]+1);
			printf("\n");
		}
		
	return 0;
}



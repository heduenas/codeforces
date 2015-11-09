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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n, m;
char A[1100][1100];
int D[3][1100][1100];
bool u[1100][1100];

int ans = -1;

void DFS(int idx, char cidx)
{
	memset(u, 0, sizeof u);
	memset(D[idx], -1, sizeof(D[idx]));
	queue<int> Q;
	for (int i = 1; i < n+1; i ++)
	{
		for (int j = 1; j < m+1; j ++)
		{
			if (A[i][j] == cidx)
			{
				Q.push(i);
				Q.push(j);
				u[i][j] = 1;
				D[idx][i][j] = 0;
			}
		}
	}
	
	while (!Q.empty())
	{
		int y = Q.front(); Q.pop();
		int x = Q.front(); Q.pop();
		
		for (int i = 0; i < 4; i ++)
		{
			if (u[y+dy[i]][x+dx[i]] == false and A[y+dy[i]][x+dx[i]] != '#')
			{
				Q.push(y+dy[i]);
				Q.push(x+dx[i]);
				u[y+dy[i]][x+dx[i]] = true;
				D[idx][y+dy[i]][x+dx[i]] = D[idx][y][x] + 1;
			}
		}
	}
}

void findmin()
{
	for (int i = 1; i < n+1; i ++)
	{
		for (int j = 1; j < m+1; j ++)
		{
			if (A[i][j] == '.' and D[0][i][j] > 0 and D[1][i][j] > 0 and D[2][i][j] > 0
			//and (D[0][i][j] == 1 or D[1][i][j] == 1 or D[2][i][j] == 1)
			)
			{
				if (ans < 0)
					ans = D[0][i][j] + D[1][i][j] + D[2][i][j]-2;
				else
					ans = min(ans, D[0][i][j] + D[1][i][j] + D[2][i][j]-2);
			}
		}
	}	
}

void findmin2()
{
	int c12 = 1<<29;
	int c13 = 1<<29;
	int c23 = 1<<29;
	for (int i = 1; i < n+1; i ++)
	{
		for (int j = 1; j < m+1; j ++)
		{
			if (A[i][j] == '1' and D[1][i][j] >= 0)
			{
				c12 = min(c12, D[0][i][j] + D[1][i][j] - 1);
			}
			if (A[i][j] == '1' and D[2][i][j] >= 0)
				c13 = min(c13, D[0][i][j] + D[2][i][j] - 1);
			if (A[i][j] == '2' and D[2][i][j] >= 0)
				c23 = min(c23, D[1][i][j] + D[2][i][j] - 1);
		}
	}
	if (ans < 0)
		ans = c12 + c13 + c23 - max(c12, max(c13, c23));
	else
		ans = min(ans, c12 + c13 + c23 - max(c12, max(c13, c23)));
	if (ans > (1 << 28))
		ans = -1;
}

int main()
{
	memset(A, '#', sizeof A);
	
	cin >> n >> m;
	for (int i = 1; i < n+1; i ++) {
		cin >> A[i]+1;
		A[i][m+1] = '#';
	}

	DFS(0, '1');
	DFS(1, '2');
	DFS(2, '3');
	
	findmin();
	findmin2();
	
	cout << ans << endl;
	return 0;
}



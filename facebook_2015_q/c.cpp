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

#define par pair<pair<int, int>, int>
#define p1 first.first
#define p2 first.second
#define p3 second

#define eps = 1e-6

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int t;
int n, m;
char M[210][210];
int sr, sc, er, ec;
int W[210][210];
int D[210][210];
int U[210][210][4];

bool test(int r, int c, int d)
{
	if (U[r][c][d] != -1 or W[r][c] == -1 or D[r][c] != -1)
		return false;
	for (int r2 = r; W[r2][c] == 0; r2 ++)
		if (D[r2][c] != -1 and (((D[r2][c]+d)%4) == 0)) // up
			return false;
		else if (D[r2][c] != -1)
			break ;
	for (int r2 = r; W[r2][c] == 0; r2 --)
		if (D[r2][c] != -1 and (((D[r2][c]+d)%4) == 2)) // down
			return false;
		else if (D[r2][c] != -1)
			break ;
	for (int c2 = c; W[r][c2] == 0; c2 ++)
		if (D[r][c2] != -1 and (((D[r][c2]+d)%4) == 3)) // left
			return false;
		else if (D[r][c2] != -1)
			break ;
	for (int c2 = c; W[r][c2] == 0; c2 --)
		if (D[r][c2] != -1 and (((D[r][c2]+d)%4) == 1)) // right
			return false;
		else if (D[r][c2] != -1)
			break ;

	return true;
}

void BFS()
{
	queue<par> Q;
	par init;
	init.p1 = sr;
	init.p2 = sc;
	init.p3 = 0;
	Q.push(init);
	U[init.p1][init.p2][0] = 0;
	while (!Q.empty())
	{
		par a = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k ++)
			if (test(a.p1+dy[k], a.p2+dx[k], (a.p3+1)%4))
			{
				par ne;
				ne.p1 = a.p1+dy[k];
				ne.p2 = a.p2+dx[k];
				ne.p3 = (a.p3+1)%4;
				U[ne.p1][ne.p2][ne.p3] = U[a.p1][a.p2][a.p3] + 1;
				Q.push(ne);
			}
	}

}

int main()
{
	cin >> t;
	int caze = 0;
	while (t--)
	{
		caze ++;
		memset(W, -1, sizeof W);
		memset(D, -1, sizeof D);
		memset(U, -1, sizeof U);
		cin >> n >> m;
		for (int i = 0; i < n; i ++)
		{
			cin >> M[i];
			for (int j = 0; j < m; j ++)
			{
				if (M[i][j] != '#')
					W[i+1][j+1] = 0;
				if (M[i][j] == 'S')
				{
					sr = i+1;
					sc = j+1;
				}
				if (M[i][j] == 'G')
				{
					er = i+1;
					ec = j+1;
				}
				if (M[i][j] == '^')
					D[i+1][j+1] = 0;
				if (M[i][j] == '>')
					D[i+1][j+1] = 1;
				if (M[i][j] == 'v')
					D[i+1][j+1] = 2;
				if (M[i][j] == '<')
					D[i+1][j+1] = 3;
			}
		}
		
		BFS();
		cout << "Case #" << caze << ": ";
		if (U[er][ec][0] == -1 and U[er][ec][1] == -1 and U[er][ec][2] == -1 and U[er][ec][3] == -1)
			cout << "impossible" << endl;
		else
		{
			unsigned int ans = -1;
			for (int i = 0; i < 4; i ++)
				ans = min((unsigned int) U[er][ec][i], ans);
			cout << ans << endl;
		}
	}
	return 0;
}

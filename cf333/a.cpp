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

int n, m;
int G[410][410];

int D[410];
queue<int> Q;
void bfs(bool color)
{
	Q.push(0);
	D[0] = 1;
	while (!Q.empty())
	{
		int nd = Q.front();
		Q.pop();
		for (int i = 0; i < n; i ++)
		{
			if (G[nd][i] == color and D[i] == 0)
			{
				Q.push(i);
				D[i] = D[nd] + 1;
			}
		}
	}
	
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i ++)
	{
		int a, b;
		cin >> a >> b;
		a --; b --;
		G[a][b] = G[b][a] = 1;		
	}
	
	bfs(!G[0][n-1]);
	cout << D[n-1]-1 << endl;
	
	/*assert(G[0][n-1] == 0);
	assert(G[0][2] == 1);
	assert(G[2][3] == 1);
	*/

	return 0;
}

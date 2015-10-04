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

int n, m;
vector<int> G[6100];
int s1, t1, l1, s2, t2, l2;
int D[3100][3100];
int ans;

void BFS(int nd)
{
	queue<int> Q;
	Q.push(nd);
	D[nd][nd] = 0;
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();

		for (int i = 0; i < G[a].size(); i++)
		{
			if (D[nd][G[a][i]] == -1)
			{
				D[nd][G[a][i]] = D[nd][a] + 1;
				Q.push(G[a][i]);
			}
		}
	}
}

int main()
{
	memset(D, -1, sizeof D);
	cin >> n >> m;
	ans = m+1;
	for (int i = 0, a, b; i < m; i ++)
	{
		cin >> a >> b;
		a --;
		b --;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cin >> s1 >> t1 >> l1;
	cin >> s2 >> t2 >> l2;
	s1 --; t1--;
	s2 --; t2--;

	for (int i = 0; i < n; i++)
		BFS(i);

	if (D[s1][t1] <= l1 and D[s2][t2] <= l2)
		ans = min(ans, D[s1][t1] + D[s2][t2]);

	for (int a = 0; a < n; a ++)
	{
		for (int b = 0; b < n; b ++)
		{
			if (D[s1][a] + D[a][b] + D[b][t1] <= l1
			and D[s2][a] + D[a][b] + D[b][t2] <= l2)
				ans = min(ans, D[s1][a] + D[a][b] + D[b][t1] + D[s2][a] + D[b][t2]);
			if (D[s1][b] + D[b][a] + D[a][t1] <= l1
			and D[s2][a] + D[a][b] + D[b][t2] <= l2)
				ans = min(ans, D[s1][b] + D[a][b] + D[a][t1] + D[s2][a] + D[b][t2]);
		}
	}

	cout << m - ans << endl;

	return 0;
}
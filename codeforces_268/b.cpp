#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int n, a, b;
int P[200100];
int G[200100][2];
int ans[200100];

pair<int, int> p2[200100];

int search(int num)
{
	int l = 1, r = n, m;
	while (l < r)
	{
		m = (l + r) /2;
		if (p2[m].first < num)
			l = m+1;
		else
			r = m;
	}
	if (p2[l].first == num)
		return p2[l].second;
	return 0;
}

bool DFS(int nd, bool turn, bool col)
{
	if (G[nd][col] == 0)
		return false;

	if (ans[nd] != -1)
		return true;

	ans[nd] = col;

	if (G[nd][turn] == 0)
		return true;
		
	return DFS(G[nd][turn], !turn, col);
}

int main () {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i ++)
	{
		cin >> P[i];
		p2[i].first = P[i];
		p2[i].second = i;
	}
	sort(p2+1, p2+n+1);

	for (int i = 1; i <= n; i ++)
	{
		int link = search(a-P[i]);
		if (link != 0)
			G[i][0] = link;

		link = search(b-P[i]);
		if (link != 0)
			G[i][1] = link;

		if (G[i][0] == 0 and G[i][1] == 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= n; i ++)
	{
		if (G[i][0] == 0 or G[i][1] == 0)
		{
			if (DFS(i, G[i][1], G[i][1]) == false)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		if (ans[i] == -1)
		{
			if (DFS(i, 0, 0) == false)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for (int i = 1; i <= n; i ++)	
	{
//		cout << ans[i] << " ";
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}

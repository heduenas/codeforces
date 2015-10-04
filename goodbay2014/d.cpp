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

vector<int> G[200100];
int n;
int E[200100][2], L[200100], count2[200100], C[200100];
int q;

int DFS(int nd, int edge)
{
	for (int i = 0; i < G[nd].size(); i ++)
	{
		if (G[nd][i] == edge)
			continue ;
		int other = E[G[nd][i]][0];
		if (other == nd)
			other = E[G[nd][i]][1];
		count2[nd] += DFS(other, G[nd][i]);
		C[G[nd][i]] = other;
	}
	count2[nd] ++;
	return count2[nd];
}

double comb(int a, int b)
{
	if (a < b)
		return 0;
	double ret = 1;
	while (b)
	{
		ret *= (double)(a) / (double)(b);
		a --;
		b --;
	}
	return ret;
}

double weight(double w, int ndc1, int ndc2)
{
	return 	2 * w * (comb(ndc1, 2) / comb(ndc1+ndc2, 3)) * ndc2
		+ 2 * w * (comb(ndc2, 2) / comb(ndc1+ndc2, 3)) * ndc1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n-1; i ++)
	{
		cin >> E[i][0] >> E[i][1] >> L[i];
		E[i][0] --;
		E[i][1] --;
		G[E[i][0]].push_back(i);
		G[E[i][1]].push_back(i);
	}
	DFS(0, -1);
	
	double ans = 0;
	for (int i = 0; i < n-1; i ++)
	{
		ans += weight(L[i], count2[C[i]], n-count2[C[i]]);
	}
	
	cin >> q;
	int eidx;
	int nw;
	for (int i = 0; i < q; i ++)
	{
		cin >> eidx >> nw;
		eidx --;
		ans -= weight(L[eidx], count2[C[eidx]], n-count2[C[eidx]]);
		L[eidx] = nw;
		ans += weight(L[eidx], count2[C[eidx]], n-count2[C[eidx]]);
		
		printf("%.7lf\n", ans);
//		cout << ans << endl;
	}

	return 0;
}



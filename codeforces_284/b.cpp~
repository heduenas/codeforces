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

int n;
int P[1001000];
int A[610][610];

vector<int> idxs;
int u[610];
int ans[610];

void DFS(int nd, int idx)
{
	if (u[nd] != 0)
		return ;
	u[nd] = idx;
	idxs.push_back(nd);
	for (int i = 0; i < n; i ++)
		if (A[nd][i])
			DFS(i, idx);
}

int main()
{
	cin >> n;
	scan(P, 0, n);
	for (int i = 0; i < n; i ++)
	{
		char str[610];
		cin >> str;
		for (int j = 0; j < n; j ++)
		{
			A[i][j] = *(str+j);
		}
	}
	
	for (int i = 0; i < n; i ++)
	{
		DFS(i, i+1);
		sort(idxs);
		for (int j = n-1; j >= 0; j --)
		{
			if (u[j] == i+1)
			{
				ans[j] = idxs[idxs.size()];
				idxs.pop_back();
			}
		}
		idxs.clear();
	}
	
	print(ans, 0, n);
	return 0;
}



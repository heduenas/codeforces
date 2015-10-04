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
#define mp make_pair

using namespace std;

const int lim =400100;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


int n, m;
vector<par> Gout[lim];
vector<par> Gin[lim];

bool ans[lim];
bool u[lim];
bool instack[lim];
stack<int> S;

void bfs(int nd)
{
	for (int i = 0; i < Gin[nd].size(); i ++)
	{
		if (u[Gin[nd][i].p1] and instack[Gin[nd][i].p1])
		{
			while (S.empty() == false and S.top() != Gin[nd][i].p1)
			{
				for (int j = 0; j < Gout[S.top()].size(); j ++)
				{
					if (!u[Gout[S.top()][j].p1] and Gout[S.top()][j].p1 != nd)
						Gin[Gout[S.top()][j].p1].push_back(mp( nd, Gout[S.top()][j].p2 ));
				}
			
				instack[S.top()] = false;
				S.pop();
			}
		}
	}
	
	u[nd] = true;
	S.push(nd);
	instack[nd] = true;
	
	for (int i = 0; i < Gout[nd].size(); i ++)
	{
		if ((!u[Gout[nd][i].p1]) or  (!instack[Gout[nd][i].p1]))
			ans[Gout[nd][i].p2] = true;
	}
	
	for (int i = 0; i < Gout[nd].size(); i ++)
	{
		if (!u[Gout[nd][i].p1])
			bfs(Gout[nd][i].p1);
	}
	
	if (S.empty() == false and S.top() == nd)
		S.pop();
	instack[nd] = false;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
	memset(ans, 0, sizeof ans);
	memset(u, 0, sizeof u);
	memset(instack, 0, sizeof instack);
    	for (int i = 0; i <= n; i ++)
    	{
    		Gout[i].clear();
    		Gin[i].clear();
    	}
    
    	for (int i = 0; i < m; i ++)
    	{
    		int a, b;
    		cin >> a >> b;
    		Gout[a].push_back(mp(b, i));
    		Gin[b].push_back(mp(a, i));
    	}
    	
    	bfs(1);
    	
    	int ansc = 0;
    	for (int i = 0; i < m; i ++)
    	{
    		ansc += ans[i];
    	}
    	cout << ansc << endl;
    	
    	for (int i = 0; i < m; i ++)
    	{
    		if (ans[i])
    			cout << i + 1 << " ";
    	}
    	cout << endl;
    }
    
    return 0;
}


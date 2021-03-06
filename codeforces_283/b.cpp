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
int P[100100];
int C[2][100100];
int score_idx[2][200100];

vector<pair<int, int> > ans; // S, T

void check(int t)
{
	int sets0 = 0, sets1 = 0;
	int score0 = 0, score1 = 0;
	int last=-1;
	
	while (score_idx[0][score0 + t] != -1 or score_idx[1][score1 + t] != -1)
	{
		if (score_idx[1][score1 + t] == -1
		or  (score_idx[0][score0 + t] != -1 and (score_idx[0][score0 + t] < score_idx[1][score1 + t])))
		{
			sets0 ++;
			score0 += t;
			score1 = C[1][score_idx[0][score0]];
			last = 0;
		} else
		{
			sets1 ++;
			score1 += t;
			score0 = C[0][score_idx[1][score1]];
			last = 1;
		}
	}
	
	if (score0 + score1 == n
	and ((last == 0 and sets0 > sets1) || (last == 1 and sets1 > sets0)))
		ans.push_back(make_pair(max(sets0, sets1), t));
}

int main()
{
	memset(score_idx, -1, sizeof score_idx);
	cin >> n;
	rep(i, n)
	{
		cin >> P[i];
		if (P[i] == 1)
			C[0][i] = 1;
		else
			C[1][i] = 1;	
	}
	
	for (int i = 1; i < n; i ++)
	{
		C[0][i] += C[0][i-1];
		C[1][i] += C[1][i-1];
	}

	for (int i = n-1; i >= 0; i --)
	{
		score_idx[0][C[0][i]] = i;
		score_idx[1][C[1][i]] = i;
	}
	
	for (int t = 1; t <= n; t ++)
		check(t);
		
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i ++)
		cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}



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
par V[100000];
int nc[100000];
int E[100000];
vector<int> B[100000];

int main()
{
	queue<int> Q;
	
	memset(E, -1, sizeof E);
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> V[i].p1 >> V[i].p2;
		if (V[i].p1 == 1)
			Q.push(i);
		m += V[i].p1;
	}
	
	while (Q.empty() == false)
	{
		int idx = Q.front();
		Q.pop();
		if (V[idx].p1 == 0)
			continue ;
		E[idx] = V[idx].p2;
		V[V[idx].p2].p2 ^= idx;
		V[V[idx].p2].p1 --;
		if (V[V[idx].p2].p1 == 1)
			Q.push(V[idx].p2);
	}
	
	cout << m / 2 << endl;
	for (int i = 0; i < 100000; i ++)
	{
		if (E[i] != -1)
			cout << i << " " << E[i] << endl;
	}
	
	return 0;
}



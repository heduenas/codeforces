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

int n, m;
int D[1000100];
int E[1000100][2];
queue<int> Q[1000100];

vector<int> ans[2];

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf ("%d%d", &E[i][0], &E[i][1]);
		D[E[i][0]] ++;
		D[E[i][1]] ++;
	}
	
	for (int i = 1; i <= m; i ++) {
		Q[min(D[E[i][0]], D[E[i][1]])].push_back (i);
	}
	
	int deg = 1;
	for (int cnt = 0; cnt < m; cnt ++) {
		ans[0].push_back(Q[deg].front()
		if (max(E[Q[deg].front][0], E[Q[deg].front][1]) == 2)
			ans[0].push_back(Q[deg].front()
	}
	
	return 0;
}  	

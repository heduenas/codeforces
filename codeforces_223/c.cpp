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

int n;
char S[1000100];
int lc[1000100];
int rc[1000100];
int c[1000100];

int m;

int DP[22][1000100];

void pre() {
	for (int i = 0; i < n; i ++)
		DP[0][i] = i;
		
	for (int lev = 1; lev <= 20; lev ++) {
		for (int i = 0; i < n; i ++) {
			if (i+(1 << (lev-1)) >= n or c[DP[lev-1][i]] < c[DP[lev-1][i+(1 << (lev-1))]])
				DP[lev][i] = DP[lev-1][i];
			else
				DP[lev][i] = DP[lev-1][i +(1 << (lev-1))];
		}			
	}
}

int RMQ(int l, int r) {
	r ++;
	int lg = 0;
	while ((1 << (lg+1)) <= (r-l))
		lg ++;
	
	if (c[DP[lg][l]] < c[DP[lg][r-(1 << lg)]])
		return DP[lg][l];
	else
		return DP[lg][r-(1<<lg)];
}

int RMQold(int l, int r) {
	int ret = l;
	while (l <= r) {
		if (c[l] < c[ret])
			ret = l;
		l ++;
	}
	return ret;
}

int main () {
	cin >> S;
	n = strlen(S);
	for (int i = 0; i < n; i ++) {
		if (S[i] == '(')
			lc[i] ++;
		else
			rc[i] ++;
		if (i) {
			lc[i] += lc[i-1];
			rc[i] += rc[i-1];
		}
		c[i] = lc[i] - rc[i];
	}
	
	pre();
	
	int l, r;
	cin >> m;
	for (int i = 0; i < m; i ++) {
		cin >> l >> r;
		l --; r --;
		int mid = RMQ(l, r);
		if (c[mid] < (l>0?c[l-1]:0))
			cout << 2 * (lc[mid] - (l>0?lc[l-1]:0)) + 2 * (rc[r] - rc[mid]);
		else
			cout << 2 * (rc[r] - (l>0?rc[l-1]:0));
		cout << endl;
	}	

	return 0;
}  	

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

double A[2010][2010];
bool DP[2010][2010];
int n, m;
int an, am;
bool u[2010], v[2010];

double f(int y, int x) {
	if (y == 0 and x == 0)
		return 0;
		
	if (DP[y][x] == false) {
		DP[y][x] = true;
		
		A[y][x] = 0;
		if (x > 0)
			A[y][x] += f(y, x-1) * ((double)(x) * (double)(n-y) / (double)(n*n));
		if (y > 0)
			A[y][x] += f(y-1, x) * ((double)(n-x) * (double)(y) / (double)(n*n));
		if (x > 0 and y > 0)
			A[y][x] += f(y-1, x-1) * ((double)(x) * (double)(y) / (double)(n*n));
			
		A[y][x] *= (double)(n*n) / ((double)(n*n) - (double)(n-y) * (double)(n-x));
	}
	return A[y][x];
}

int main () {
	cin >> n >> m;
	an = n; am = m;
	for (int i = 0, r, c; i < m; i ++) {
		cin >> r >> c;
		ar -= u[r] == false;		u[r] = true;
		ac -= v[c] == false;		v[c] = true;
	}
	
	cout << f(ar, ac) << endl;
	
	return 0;
}  	

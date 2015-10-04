#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, m, y, x;
int X[1000010], Y[1000010];
int Xa[1000010], Ya[1000010];
int ans, ansa;

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		cin >> x >> y;
		X[x] = 1;
		Y[y] = 1;
		Xa[y] = 1;
		Ya[x] = 1;
	}
	
	for (int i = 2; i <= n-1; i ++)
		if (n % 2 == 0 or (i != (n+1)/2)) {
			ans += 1 - X[i];
			ans += 1 - Y[i];
			ansa += 1 - Xa[i];
			ansa += 1 - Ya[i];
		} else {
			ans += 1 - Y[i];
			ansa += 1 - Ya[i];
		}
		
	cout << max (ans, ansa) << endl;

	return 0;
} 

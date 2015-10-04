#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, m;
int X[110];
pair<int, int> Y[110];
bool u[110];

int DP[110][110];

int F(int y, int x) {
	if (y == -1 or Y[y].first == 0 or x == -1)
		return 0;
		
	if (DP[y][x] == -1) {
		DP[y][x] = 0;
		if (Y[y].second <= X[x])
			DP[y][x] = -Y[y].second + X[x] + F(y-1, x-1);
		DP[y][x] = max(DP[y][x], max (F(y-1, x), F(y, x-1)));
	}
	return DP[y][x];
}

int main () {
	cin >> n >> m;
	char str[10];
	for (int i = 0; i < n; i ++) {
		scanf ("%s", str);
		Y[i].first = str[0] == 'A';
		cin >> Y[i].second;
	}
	for (int i = 0; i < m; i ++) {
		cin >> X[i];
	}
	
	sort (X, X + m);
	sort (Y, Y + n);
	
	memset (DP, -1, sizeof DP);
	int ans1 = F(n-1, m-1);
	
	int x = 0, y = 0;
	while (x < m and y < n and Y[y].first == 0) {
		while ((Y[y].second >= X[x]) and      (x < m))
			x ++;
		if (x < m)
			u[x] = true;
		y ++;
		x ++;
	}
	if (x > m or (y < n and Y[y].first == 0)) {
		printf ("%d\n", ans1);
		return 0;
	}
	
	int ans2 = 0;
	x = 0;
	while (x < m and y < n) {
		while ((u[x] or Y[y].second > X[x]) and      (x < m))
			x ++;
		if (x < m) {
			u[x] = true;
			ans2 += X[x];
			ans2 -= Y[y].second;
		}
		y ++;
		x ++;
	}
	
	if (x > m or y < n) {
		printf ("%d\n", ans1);
		return 0;
	}
	
	for (int i = 0; i < m; i ++) {
		if (!u[i])
			ans2 += X[i];
	}
	
	printf ("%d\n", max (ans1, ans2));
	
	return 0;
}

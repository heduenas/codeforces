#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int n, m, x, y, dir, count;
bool U[4][100010][4];
long long ans = 0;

int Bounce (int x, int y, int d) {
	if (y == 0)
		d = (d+1) % 4;
	if (y == n-1)
		d = (d+3) % 4;
	if (x == 0)
		d = (d+2) % 4;
	if (x == m-1)
		d = (d+2) % 4;
		
	return d;
}

void Process (int x, int y, int d) {
	int ak= -1;
	if (y == 0)
		ak = 0;
	else if (y == n-1)
		ak = 1;
	else if (x == 0)
		ak = 2;
	else if (x == m-1)
		ak = 3;
	
	if (ak > -1) {
		if (!(U[ak][x][0] or U[ak][x][1] or U[ak][x][2] or U[ak][x][3]))
			count ++;
			
		if (U[ak][x][d]) {
			ans = -1;
			return ;
		}
		U[ak][x][d] = true;
	}
	
		
		
	x += min (m-x-1, n-y-1);
	y += min (m-x-1, n-y-1);
	ans += min (m-x-1, n-y-1);
	
	if (count == (n / 2) + (m / 2)) {
		return ;
	}
	
	Process	(x, y, Bounce (x, y, d));
}

int main() {
	scanf ("%d%d%d%d", &n, &m, &x, &y);
	x --; y --;
	char str[100];
	scanf ("%s", str);
	if (str[0] == 'D' and str[1] == 'R')
		dir = 0;
	if (str[0] == 'U' and str[1] == 'L')
		dir = 1;
	if (str[0] == 'D' and str[1] == 'L')
		dir = 2;
	if (str[0] == 'U' and str[1] == 'R')
		dir = 3;
		
	Process (x, y, dir);
	
	cout << ans << endl;
	
	return 0;
}

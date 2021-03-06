#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int n, m;
char M[2010][2010];
int cnt[2010][2010];

const int inf = 1 << 30;

vector<int> S;
bool explore2 (int y, int x, bool mod) {
	S.push_back (x);
	S.push_back (y);
	if (cnt[y][x] == inf)
		return true;
	if (cnt[y][x] == -1) {
		if (M[y][x] == '#')
			cnt[y][x] = 0;
		else if (M[y][x] == 'x')
			cnt[y][x] = 0;
		else
			cnt[y][x] = inf;
	}
	return false;
}

int explore (int y, int x, bool mod = false) {
	S.clear ();
	if (explore2 (y, x, mod))
		return inf;
		
	while (cnt[y][x] == inf) {
			
		if (M[y][x] == '<') {
			if (explore2 (y, x-1, mod))
				return inf;
			x --;
		} else if (M[y][x] == '>') {
			if (explore2 (y, x+1, mod))
				return inf;
			x ++;
		} else if (M[y][x] == '^') {
			if (explore2 (y-1, x, mod))
				return inf;
			y --;
		} else if (M[y][x] == 'v') {
			if (explore2 (y+1, x, mod))
				return inf;
			y ++;
		}
	}
	
	int prev = cnt[S[S.size() -1]][S[S.size() -2]];
	if (mod)
		M[S[S.size() -1]][S[S.size() -2]] = '#';
	int k = 1;
	for (int i = S.size() -3; i >= 0; i -= 2, k ++) {
		y = S[i];
		x = S[i-1];
		cnt[y][x] = prev + 1;
		prev = prev + 1;
		if (mod)
			M[y][x] = '#';
	}
	return cnt[y][x];
}

int main () {	
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> M[i];
	
	memset (cnt, -1, sizeof cnt);
	
	int ansa = 0, ansb = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (explore(i, j) > ansa)
				ansa = explore (i, j);
	
	if (ansa == inf) {
		printf ("-1\n");
		return 0;
	}
	
	bool done = false;			
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++)
			if (explore(i, j) == ansa) {
				memset (cnt, -1, sizeof cnt);
				explore (i, j, true);
				M[i][j] = 'x';
				done = true;
				break;
			}
			
		if (done)
			break;
	}
			
	memset (cnt, -1, sizeof cnt);
	ansb = ansa - 1;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (explore(i, j) > ansb)
				ansb = explore (i, j);
		
	cout << ansa + ansb << endl;
	return 0;
}  	

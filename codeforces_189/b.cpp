#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int I[1010][2], q, v;
bool u[1010];

bool DFS (int nd) {
	if (u[nd]) {
		return true;
	}
	u[nd] = true;
	for (int i = 0; i < v; i ++) {
		if (((I[nd][0] < I[i][1]) and (I[nd][0] > I[i][0])) or ((I[nd][1] < I[i][1]) and (I[nd][1] > I[i][0])))
			DFS (i);
	}
	return true;
}

int main () {
	cin >> q;
	for (int i = 0, t, a ,b; i < q; i ++) {
		cin >> t >> a >> b;
		memset (u, sizeof u, 0);
		for (int i = 0; i < v; i ++)
			u[i] = false;
		if (t == 1) {
			I[v][0] = a;
			I[v][1] = b;
			v ++;
		} else {
			DFS (a-1);
			if (u[b-1]) {
				printf ("YES\n");
			} else {
				printf ("NO\n");
			}
		}
	}

	return 0;
}

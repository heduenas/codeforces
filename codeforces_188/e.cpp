#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, v, e;
int A[500], B[500], C[500];
int G[500][500];
int SP[500][500];

int ansc, ans[1000000][3];

bool Ua[500], Ub[500];

queue<int> Q;

void DFS (int nd) {
	Q.push (nd);
	SP[nd][nd] = nd;
	
	while (!Q.empty()) {
		int a = Q.front ();
		Q.pop ();
		
		for (int i = 0; i < n; i ++)		
			if (G[a][i] and (SP[nd][i] == -1)) {
				SP[nd][i] = a;
				Q.push (i);
			}
	}
}

int DifA (int nd) {
	if (Ua[nd])
		return 0;
	Ua[nd] = true;
	int ret = A[nd];
	for (int i = 0; i < n; i ++)
		if (G[nd][i])
			ret += DifA (i);
	
	return ret;
}

int DifB (int nd) {
	if (Ub[nd])
		return 0;
	Ub[nd] = true;
	int ret = B[nd];
	for (int i = 0; i < n; i ++)
		if (G[nd][i])
			ret += DifB (i);
	
	return ret;
}

int main() {
	memset (SP, -1, sizeof SP);
	
	cin >> n >> v >> e;
	for (int i = 0; i < n; i ++) {
		cin >> A[i];
		C[i] = A[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> B[i];
	}
	
	for (int i = 0, a, b; i < e; i ++) {
		cin >> a >> b;
		a --; b --;
		G[a][b] = G[b][a] = true;
	}
	
	for (int i = 0; i < n; i ++) {
		if (DifA (i) - DifB (i) != 0) {
			printf ("NO\n");
			return 0;
		}
	}
	
	for (int i = 0; i < n; i ++)
		DFS (i);
		
	for (int i = 0; i < n; i ++)
		if (C[i] > B[i])
			Q.push (i);
			
	while (!Q.empty ()) {
		int s = Q.front (), t;
		int ex = C[s] - B[s];
		Q.pop ();
		
		for (int i = 0; i < n; i ++)
			if ((C[i] < B[i]) and (SP[i][s] != -1)) {
				t = i;
				break ;
			}
		
		do {
			ans[ansc][0] = s;
			ans[ansc][1] = SP[t][s];
			ans[ansc][2] = ex;
			ansc ++;
			t = SP[t][s];
		} while (SP[t][s] != t);
		
		C[t] += ex;
		C[s] = B[s];
		if (C[t] > B[t])
			Q.push (t);
	}
	
	printf ("%d\n", ansc);
	for (int i = 0; i < ansc; i ++) {
		printf ("%d %d %d\n", ans[i][0]+1, ans[i][1]+1, ans[i][2]);
	}
	
	return 0;
}

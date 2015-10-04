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

struct graph {
	int n;
	vector<int> E[200100];
	long long D[2010][2010];
	long long SD[200100];
	long long totD;
	int max_idx;
	
	void read() {
		for (int i = 0, a, b; i < n-1; i ++) {
			cin >> a >> b;
			a --; b --;
			E[a].push_back(b);
			E[b].push_back(a);
		}
	}
	
	void dfs (int rt, int nd, long long dist, int prev = -1) {
		D[rt][nd] = dist;
		for (int i = 0; i < E[nd].size(); i ++)
			if (E[nd][i] != prev)
				dfs (rt, E[nd][i], dist + 1, nd);
	}
		
	void expand() {
		max_idx = 0;
		for (int i = 0; i < n; i ++) {
			dfs(i, i, 0);
			for (int j = 0; j < n; j ++)
				SD[i] += D[i][j];
			totD += SD[i];
			if (SD[i] > SD[max_idx])
				max_idx = i;
		}
		totD /= 2;
	}	
} G[3];

long long ans;

int main () {	
	cin >> G[0].n >> G[1].n >> G[2].n;
	for (int i = 0; i < 3; i ++) {
		G[i].read();
		G[i].expand();
	}
	
	for (int z = 0; z < 3; z ++) {
	if (z != 1) {
		swap(G[z].n, G[1].n);
		swap(G[z].E, G[1].E);
		swap(G[z].D, G[1].D);
		swap(G[z].SD, G[1].SD);
		swap(G[z].totD, G[1].totD);
		swap(G[z].max_idx, G[1].max_idx);
	}
	
	int i = 0, j = 0;
	int maxi=0, maxj = 0;
	for (i = 0; i < G[1].n; i ++) {
		for (j = 0; j < G[1].n; j += 1) {
			if (G[1].D[i][j] > G[1].D[maxi][maxj]) {
				maxi = i;
				maxj = j;
			}
		}
	}
	
	i = maxi;
	j = maxj;
	
			long long opt = G[0].totD + G[1].totD + G[2].totD;
			opt += G[0].SD[G[0].max_idx] * G[1].n;
			opt += G[1].SD[i] * G[0].n;
			opt += G[0].n * G[1].n;
			
			opt += G[1].SD[j] * G[2].n;
			opt += G[2].SD[G[2].max_idx] * G[1].n;
			opt += G[1].n * G[2].n;
			
			opt += G[0].SD[G[0].max_idx] * G[2].n;
			opt += G[2].SD[G[2].max_idx] * G[0].n;
			opt += G[0].n * G[2].n * (G[1].D[i][j] + 2);
			
			ans = max(opt, ans);
	
	if (z != 1) {
		swap(G[z].n, G[1].n);
		swap(G[z].E, G[1].E);
		swap(G[z].D, G[1].D);
		swap(G[z].SD, G[1].SD);
		swap(G[z].totD, G[1].totD);
		swap(G[z].max_idx, G[1].max_idx);
	}
	
	}
	
	cout << ans << endl;
	
	return 0;
}  	

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define SIZE 1 << 21
using namespace std;

struct ST {
	void init (int n_) {
		n = 1;
		while (n < n_)
			n <<= 1;
	}
	void update (int idx, int val) {
		int nd = n - 1 + idx;
		d[nd] = val;
		do {
			nd = (nd-1) / 2;
			d[nd] = min (d[nd * 2 + 1], d[nd * 2 +2]);
		} while (nd > 0);
	}
	int query (int ql, int qr, int nd = 0, int rl = 0, int rr = -1) {
		if (rr == -1)
			rr = n-1;
		if (ql > rr || qr < rl)
			return 1 << 30;
		if (rl >= ql && rr <= qr)
			return d[nd];
		return min (query (ql, qr, nd * 2 + 1, rl, (rr + rl)/2), query (ql, qr, nd * 2 + 2, (rr + rl) / 2 + 1, rr));
	}
	int n, d[SIZE];
} st;

int n;
vector<int> G[SIZE];

int main () {
	cin >> n;
	for (int i = 0, a, b; i < n-1; i ++) {
		cin >> a >> b;
		a --; b --;
		G[a].push_bakc (b);
		G[b].push_bakc (a);
	}
	
	
	
	return 0;
} 

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
long long A[100100], sum;
vector<int> G[100100];
long long weight[100100];
long long lcm[100100];

long long gcd (long long a, long long b) {
	if (b == 0)
		return a;
	return gcd (b, a % b);
}

long long LCM (long long a, long long b) {
	return a * (b / gcd (a, b));
}

void DFS (int nd, int pnt) {
	long long min = 10000000000000000ll;
	lcm[nd] = 1;
	long long cnt = 0;
	for (int i = 0, f = G[nd].size (); i < f; i ++) {
		if (G[nd][i] != pnt) {
			DFS (G[nd][i], nd);
			if (min > weight[G[nd][i]])
				min = weight[G[nd][i]];
			lcm[nd] = LCM (lcm[G[nd][i]], lcm[nd]);
			
			cnt ++;
		}
	}
	if (cnt == 0) {
		weight[nd] = A[nd];
	} else {
		weight[nd] = min / lcm[nd];
		weight[nd] *= lcm[nd] * cnt;
		lcm[nd] *= cnt;
	}
}

int main () {
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &A[i]);
		sum += A[i];
	}

	for (int i = 0, a, b; i < n-1; i ++) {
		cin >> a >> b;
		a --; b --;
		G[a].push_back (b);
		G[b].push_back (a);
	}
	
	DFS (0, 0);
	
	cout << sum - weight[0] << endl;
	
	return 0;
} 

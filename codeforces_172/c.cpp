#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
using namespace std;

int n;
vector<int> E[200010];
vector<int> wi[200010];
vector<double> w[200010];
bool u[200010];
double DP[200010];		// number of nodes in subtrees

double F (int nd) {
	if (u[nd])
		return 0.0f;
	u[nd] = true;
	
	double ret = 0.0f;
	double nodec = 0;
	double tmp;
	
	for (int i = 0, f = E[nd].size (); i < f; i ++) {
		tmp = F(E[nd][i]);
		if (tmp > 0.0f) {
			w[nd].push_back(tmp);
			wi[nd].push_back(E[nd][i]);
			nodec += DP[E[nd][i]];
		}
	}
	
	for (int i = 0, f = w[nd].size (); i < f; i ++) {
		//w[nd][i] *= DP[wi[nd][i]] / nodec;
		ret += w[nd][i];
	}
	
	nodec += 1.0f;
	ret = 1.0f + ret / 2.0f;
	
	DP[nd] = nodec;
	return ret;
}

int main () {
	cin >> n;
	for (int i = 0, a, b; i < n-1; i ++) {
		scanf ("%d%d", &a, &b);
		a --; b --;
		E[a].push_back (b);
		E[b].push_back (a);
	}
	
	printf ("%.12lf\n", F(0));
	
	return 0;
} 

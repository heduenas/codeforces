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

int P[200010];
int n, m, s;
pair<int, int> A[200010];
pair<pair<int, int>, int> BC[200010];  //((b, c), idx)

priority_queue<pair<int, int> > Q;

bool f (int mid, bool print = false) {
	long long cost = 0;
	int sidx = n-1;
	int bidx = m-1;
	while (!Q.empty ())
		Q.pop ();
	
	while (bidx >= 0) {
		while (sidx >= 0 and BC[sidx].first.first >= A[bidx].first) {
			Q.push (make_pair (-BC[sidx].first.second, sidx));
			sidx --;
		}
		
		if (Q.empty ())
			return false;
		
		int stuidx = BC[Q.top ().second].second;
		cost += (long long )(BC[Q.top ().second].first.second);
		Q.pop ();
		
		if (print)
			for (int i = 0; i < mid; i ++)
				if (bidx-i >= 0)
					P[A[bidx-i].second] = stuidx;
		
			
		bidx -= mid;
	}
	
	if (cost <= s)
		return true;
	else
		return false;
}

int main () {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i ++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	for (int i = 0; i < n; i ++) {
		cin >> BC[i].first.first;
		BC[i].second = i;
	}
	for (int i = 0; i < n; i ++)
		cin >> BC[i].first.second;
	
	sort (A, A+m);
	sort (BC, BC+n);
	
	int l = 1, r = m, mid;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (f (mid))
			r = mid;
		else
			l = mid + 1;
	}
	
	if (f (l)) {
		cout << "YES" << endl;
		f (l, true);
		for (int i = 0; i < m; i ++)
			printf ("%d ", P[i]+1);
		printf ("\n");
	} else
		cout << "NO" << endl;
		
	
	return 0;
}  	

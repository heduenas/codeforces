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


int n, ans;
pair<int, int> S[500000];
pair<int, int> Sm;
set<pair<int, int> > L;
set<pair<int, int> > Lm;

int main () {
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &S[i].first);
		S[i].second = i;
	}
	
	sort (S, S + n);
	
	set<pair<int, int> >::iterator low, up;
	
	for (int i = n-1; i>=0; i --) {
		swap (S[i].first, S[i].second);
		L.insert (S[i]);
		Sm = make_pair(-S[i].first, S[i].second);
		Lm.insert (Sm);
		
		low = Lm.upper_bound (Sm);
		up = L.upper_bound (S[i]);
		
		if (low != Lm.end ())
			ans = max (ans, (*low).second ^ S[i].second);
		if (up != L.end ())
			ans = max (ans, (*up).second ^ S[i].second);
		
	}
	
	cout << ans << endl;
	
	return 0;
} 

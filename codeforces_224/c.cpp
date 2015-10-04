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

long long n;
long long A[100100];
set<long long> D;
vector<long long> ans;

int main () {	
	cin >> n;
	scan(A, 0, n);
	sort (A, A+n);
	for (int i = 1; i < n; i ++)
		D.insert (A[i]-A[i-1]);
		
	if (D.size () > 2) {
		printf ("0\n");
		return 0;
	}
	vector<long long> Dv(D.begin (), D.end ());
	sort (Dv.begin(), Dv.end());
	if (Dv.size() == 2 and (Dv[1] == Dv[0] * 2)) {
		for (int i = 1; i < n; i ++) {
			if (A[i]-A[i-1] == Dv[1]) {
				if (ans.size () > 0) {
					printf("0\n");
					return 0;
				}
				ans.push_back (A[i-1] + Dv[0]);
			}
		}
	} else if (Dv.size() == 1) {
		if (n == 2 and (Dv[0]%2) == 0)
			ans.push_back (A[0] + Dv[0] / 2);
		ans.push_back (A[0] - Dv[0]);
		ans.push_back (A[n-1] + Dv[0]);
	} else if (Dv.size() == 0) {
		printf ("-1\n");
		return 0;
	} else {
		printf ("0\n");
		return 0;
	}
	sort (ans.begin(), ans.end());
	while (ans.size() > 1 and ans[ans.size() -1] == ans[ans.size() -2])
		ans.pop_back ();
		
	cout << ans.size() << endl;
	print(ans, 0, ans.size());
	if (ans.size())
		printf ("\n");
		
	return 0;
}  	

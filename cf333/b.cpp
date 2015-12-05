#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <cassert>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>

#define deb(x) cout << #x << " = " << x << endl;
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

template <typename T> 
struct ST {
	int n;
	const static int SIZE = 1 << 18;			
	pair<T, int> d[SIZE];
	void init(int n_) {
		n = 1;
		while (n < n_)
			n <<= 1;
	}
	void update(int idx, T val) {
		int nd = n - 1 + idx;
		d[nd] = make_pair(val, idx);
		while (nd > 0) {
			nd = (nd-1) / 2;
			d[nd] = max(d[nd * 2 + 1], d[nd * 2 +2]);
		}
	}
	// queries are inclusive in both ends
	pair<T, int> query(int ql, int qr, int nd = 0, int rl = 0, int rr = -1) {
		if (rr == -1)
			rr = n-1;
		if (ql > rr || qr < rl)
			return make_pair(-1, -1);
		if (rl >= ql && rr <= qr)
			return d[nd];
		return max(query(ql, qr, nd * 2 + 1, rl, (rr + rl)/2), query(ql, qr, nd * 2 + 2, (rr + rl) / 2 + 1, rr));
	}
};
ST <int> st;


int n, q;
int H[200100];
int q1, q2;

long long Query(int a, int b)
{		
	//if (a > b)
	//	return 0;
	if (a == b)
		return abs(H[a] - H[a+1]);
	pair<int, int> pivot = st.query(a, b);
		
	return (long long)(pivot.second - a + 1) * (long long)(b - pivot.second + 1) * (long long)pivot.first
		+ ( pivot.second>a?Query(a, pivot.second-1):0) 
		+ ( pivot.second<b?Query(pivot.second+1, b):0);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i ++)
		scanf("%d", &H[i]);
	st.init(n-1);
	for (int i = 0; i < n-1; i ++)
	{
		st.update(i, abs(H[i] - H[i+1]));
	}
	
	for (int i = 0; i < q; i ++)
	{
		scanf("%d%d", &q1, &q2);
		if (st.query(0, n-2).first <= 1)
			printf("%I64d\n", st.query(q1-1, q2-2).first * ((long long)(q2-q1) * (long long)(q2-q1+1)) / 2ll);
		else
			printf("%I64d\n", Query(q1-1, q2-2));
	}

	return 0;
}

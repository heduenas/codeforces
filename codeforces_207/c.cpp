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

int n, m;
int R[500100][3];
vector<int> A[500100];
bool in[500100];

int ans[500100];

priority_queue<int> Q;

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		scanf ("%d%d%d", &R[i][0], &R[i][1], &R[i][2]);
		
		A[R[i][0]].push_back (i);
		A[R[i][1]+1].push_back (i);
		A[R[i][2]].push_back (i);
		A[R[i][2]+1].push_back (i);
		
	}
	
	for (int i = 1; i <= n; i ++) {
			
		while (!Q.empty () and !in[-Q.top ()])
			Q.pop ();
			
		while (A[i].size () != 0) {
			if (!in[A[i].back ()])
				Q.push (-A[i].back ());
			in[A[i].back ()] = !in[A[i].back ()];
			A[i].pop_back ();
		}
			
		while (!Q.empty () and !in[-Q.top ()])
			Q.pop ();
			
		if (Q.empty () == true)
			ans[i] = 0;
		else
			ans[i] = R[-Q.top ()][2];
		printf ("%d ", ans[i]);
	}
	
	
	return 0;
}  	

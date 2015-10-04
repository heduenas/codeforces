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

int k, n;
long long P[500100], E[500100];
int A[500100];
long long ans;

int main () {	
	cin >> n >> k;
	for (int i = 0; i < n; i ++)
		cin >> P[i] >> E[i];
	
	ans = 1ll <<50;
	
	for (int i = 0; i < (1 << n); i ++) {
		int points = 0, rank = n+1;
		long long cost = 0;
			
		for (int j = 0; j < n; j ++) {
			if (i & (1 << j)) {
				points ++;
				cost += E[j];
				A[j] = P[j];
			} else
				A[j] = P[j] + 1;
		}
		
		for (int j = 0; j < n; j ++) {
			if (points > A[j])
				rank --;
			else if (points == A[j] and (i & (1 << j)))
				rank --;
		}
		
		if (rank <= k)
			ans = min(ans, cost);
	}
	
	if (ans == 1ll <<50)
		ans = -1;
	
	cout << ans << endl;
	
	return 0;
}  	

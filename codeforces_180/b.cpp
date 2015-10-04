#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, m, k;
int A[100010], B[100010];

bool notans = true;

int main () {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i ++)
		scanf ("%d", A + i);
	for (int i = 0; i < m; i ++)
		scanf ("%d", B + i);
		
	sort (A, A + n);
	sort (B, B + m);
	
	if (n > m) {
		notans = false;
	}
	else {
		int a = n -1, b = m -1;
		while (a >= 0 and b >= 0) {
			if (A[a] > B[b])
				notans = false;
			a --; b --;
		}
	}
	
	if ( notans)
		cout << "NO\n";
	else
		cout << "YES\n";
	
	return 0;
}  

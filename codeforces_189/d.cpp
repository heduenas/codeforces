#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, A[1001000];
int L[1000100];
int SL[1000100];
bool D[1000100];

stack<int> S;

int main () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &A[i+1]);
		L[i+1] = i+2;
	}
	A[0] = 0;
	L[0] = 1;
	A[n+1] = 1000000000;
	
	for (int i = n+1; i >= 0; i --) {
		SL[i] = i;
		int j;
		for (j = i-1; (j >= 0) and (A[j] < A[j+1]); j --) {
			SL[j] = i;
		}
		i = j +1;
	}
	
	int ans = 0;
	bool any;
	do {
		any = false;
		for (int i = 0; i != n+1; ) {
			if (A[i] > A[L[i]]) {
				S.push (i);
				any = true;
				i = L[i];
			} else if (SL[i] == i) {
				i = L[i];
			} else {
				i = SL[i];
				while (D[i]) {
					i = L[i];
				}
			}
		}
		
		while (!S.empty ()) {
			int i = S.top ();
			S.pop ();
			
			D[L[i]] = true;
			L[i] = L[L[i]];
			if (A[i] < A[L[i]])
				SL[i] = SL[L[i]];
		}
		ans += any;
	} while (any);
	
	cout << ans << endl;
	
	return 0;
}

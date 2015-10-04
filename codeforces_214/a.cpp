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

int n;
int A[4][4];

int ans_a = 1000000, ans_b  = 1000000;
int ans_idx = -1;

int main () {
	cin >> n;
	scan (A[0], 0, 4);
	scan (A[1], 0, 4);
	scan (A[2], 0, 4);
	scan (A[3], 0, 4);
	
	for (int i = 0; i < 4; i ++) {
		if (ans_a + ans_b > min (A[i][0], A[i][1]) + min (A[i][2], A[i][3])) {
			ans_idx = i+1;
			ans_a = min (A[i][0], A[i][1]);
			ans_b = min (A[i][2], A[i][3]);
		}
	}
	
	if (ans_idx != -1 and ans_a + ans_b <= n)
		cout << ans_idx << " " << ans_a << " " << n - ans_a << endl;
	else
		cout << -1 << endl;
	
	return 0;
}  	

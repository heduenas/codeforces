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

int n, A[1000010];
int B[1000010], bc;

int main () {	
	cin >> n;
	scan(A, 0, n);
	
	sort (A, A + n);
	
	for (int i = 0; i < n; i ++) {
		sort (B, B + bc);
		if (bc == 0 or B[0] > A[i])
			B[bc ++] = 1;
		else
			B[0] ++;
	}
	
	cout << bc << endl;

	return 0;
}  	

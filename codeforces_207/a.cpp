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

int n, A[1100], x, y;

int main () {
	cin >> n;
	scan (A, 1, n+1);
	cin >> x >> y;
	
	int left = 0, right = 0;
	
	for (int i = 1; i <= n; i ++)
		right += A[i];
		
	if (x <= left and left <= y and x <= right and right <= y) {
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 1; i <= n; i ++) {
		if (x <= left and left <= y and x <= right and right <= y)  {
			cout << i << endl;
			return 0;
		}
		left += A[i];
		right -= A[i];
	}
	
	cout << 0 << endl;
	
	return 0;
}  	

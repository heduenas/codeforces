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

int n, k, np;

const int cte = 1000000000;

int main () {
	cin >> n >> k;
	np = n >> 1;
	
	if ((np > k) or (np == 0 and k > 0)) {
		cout << -1 << endl;
		return 0;
	}
		
	if (np)
		cout << 2 * (k - np + 1) << " " << k - np + 1;
	
	for (int i = 1; i < np; i ++)
		cout << " " << cte - (2 * i) << " " << cte - 1 - (2 * i);
	if ((n % 2)) {
		if (np)
			cout << " ";
		cout << cte - (2 * np);
	}
	cout << endl;

	return 0;
}  	

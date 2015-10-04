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

int main () {
	cin >> n >> m;
	int day = 1;
	int socks = n;

	while (socks) {
		socks --;
		day ++;
		if (day > m and (day % m) == 1)
			socks ++;
	}

	cout << day-1 << endl;

	return 0;
}  	

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
using namespace std;

int n, A[210];

unsigned int __gcd (unsigned int a, unsigned int b) {
	if (b == 0)
		return a;
	return __gcd (b, a%b);
}

int main () {
	cin >> n;
	scan (A, 0, n);
	sort (A, A + n);
	reverse (A, A + n);
	
	unsigned int gcd = A[0];
	for (int i = 1; i < n; i ++)
		gcd = __gcd (gcd, A[i]);
		
	if ((A[0] / gcd - n)%2 == 0)
		printf ("Bob\n");
	else
		printf ("Alice\n");
	return 0;
} 

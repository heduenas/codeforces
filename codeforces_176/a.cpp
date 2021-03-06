#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
int P[1000010];

int main () {
	cin >> n;
	
	if (n%4 > 1) {
		cout << -1 << endl;
		return 0;
	}
	
	if (n%2 == 1)
		P[(n+1)/2] = (n+1)/2;
	
	for (int i = 1; i <= n/2; i += 2) {
		P[i] = i+1;
		P[i+1] = n-i+1;
		P[n-i+1] = n-i;
		P[n-i] = i;
//		cout << i << " " << i+1 << " " << n-i+1 <<  " " << n-i << " ";
	}
	
	for (int i = 1; i <= n; i ++)
		cout << P[i] << " ";
	
	return 0;
} 

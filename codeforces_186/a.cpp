#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, a, b, c;

int main () {
	cin >> n;
	a = n;
	b = n / 10;
	c = (n / 100) * 10 + (n % 10);
	
	cout << max (c, max (a, b)) << endl;	

	return 0;
}

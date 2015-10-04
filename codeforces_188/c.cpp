#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

long long a, b, m;

int main() {
	cin >> a >> b >> m;
	long long i = 0;
	
	if (a + b > min(a, b))
	for (i = 0; (a < m) and (b < m); ) {
		if (a > b)
			swap (a, b);
		
		long long t = 1 + (b - a) / b;
		a += b * t;
		i += t;
	}
	
	if ((a >= m) or (b >= m))
		cout << i << endl;
	else
		printf ("-1\n");
	
	return 0;
}

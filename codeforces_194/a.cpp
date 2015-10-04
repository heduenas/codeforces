#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

long long n, ans;

int main () {
	cin >> n;
	
	long long i;
	
	for ( i = 1; i <= n; i *= 3) {
		if ((n / i) % 3 > 0)
			break ;
	}
	i *= 3;
	
	ans = (n + i - 1) / i;
	
	cout << ans << endl;

	return 0;
} 

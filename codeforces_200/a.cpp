#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

unsigned long long a, b, ans;

int main () {
	cin >> a >> b;

	while (a > 1 or b > 1) {
		if (b > a) {
			swap (a, b);
		}
		
		ans += a / b;
		a -= b * (a / b);
	}
		
	cout << max(ans, 1ull) << endl;
	
	return 0;
} 

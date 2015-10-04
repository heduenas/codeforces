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

char str[1000010];
int ans;

int main () {	
	cin >> str;
	for (char *c = str; *c; c ++) {
		int cnt = 1;
		while (*(c+1) and *c == *(c+1)) {
			c ++;
			cnt ++;
		}
		ans += cnt % 2 == 0;
	}
	cout << ans << endl;
	
	return 0;
}  	

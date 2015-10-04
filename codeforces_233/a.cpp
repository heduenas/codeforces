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

long long a, b;
long long ans;

int main () {
	cin >> a >> b;
	if (a*a >= (b/2)*(b/2) + ((b+1)/2) * ((b+1)/2)) {
		cout << a*a - (b/2)*(b/2) - ((b+1)/2) * ((b+1)/2) << endl;
		for (long long i = 0; i < (b+1)/2; i++)
			cout << "x";
		for (long long i = 0; i < a; i++)
			cout << "o";
		for (long long i = 0; i < b/2; i++)
			cout << "x";
		cout << endl;
	} else {
		long long sp = b / (a+1), ak = b % (a+1);
		
		ans = 0;
		for (int i = 0; i <ak; i ++)
			ans += (sp+1)*(sp+1);
		for (int i = 0; i < a+1-ak; i ++)
			ans += sp*sp;
		ans = a-ans;
		
		cout << ans << endl;
		
		
		for (int i = 0; i < a+1; i ++) {
			for (int j = 0; j < sp + (i < ak); j ++)
				cout << "x";
			if (i < a)
				cout << "o";
		}
		cout << endl;
	}
	
	return 0;
}  	

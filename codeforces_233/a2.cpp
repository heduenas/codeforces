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

void gen(long long strips) {
	long long sp = b / (strips+1), ak = b % (strips+1);

	for (int i = 0; i < strips+1; i ++) {
		for (int j = 0; j < sp + (i < ak); j ++)
			cout << "x";
		if (i < strips) {
			if (i > 0)
				cout << "o";
			else
				for (int j = 0; j < a - strips + 1; j ++)
					cout << "o";
		}
	}
		cout << endl;
}

long long f(long long strips) {
	long long ret = (a - strips +1) * (a - strips +1) + strips - 1;
	
	
		long long sp = b / (strips+1), ak = b % (strips+1);
		
		for (int i = 0; i <ak; i ++)
			ret -= (sp+1)*(sp+1);
		for (int i = 0; i < strips+1-ak; i ++)
			ret -= sp*sp;
		
	return ret;
}

int main () {
	cin >> a >> b;
	
	if (a == 0 or b == 0) {
		cout << a * a - b * b << endl;
		for (int i = 0; i < a; i ++)
			cout << "o";
		for (int i = 0; i < b; i ++)
			cout << "x";
		cout << endl;
		return 0;
	}
	
	ans = -(1ll << 50);
	int argans;
	for (int i = 1; i <= min(max(a, 1ll), max(b-1, 1ll)); i ++) {
		long long opt = f(i);
		if (opt > ans) {
			argans = i;
			ans = opt;
		}
	}
	cout << ans << endl;
	gen(argans);

	return 0;
}  	

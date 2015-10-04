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

int n;

int main () {
	cin >> n;
	if (n < 4) 
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	int i;
	if ((n%2) == 0) {
		cout 	<< "1 * 2 = 2" << endl
			<< "2 * 3 = 6" << endl
			<< "6 * 4 = 24" << endl;
		i = 5;
	} else {
		cout << "5 * 4 = 20" << endl
		<< "3 - 1 = 2" << endl
		<< "2 * 2 = 4" << endl
		<< "20 + 4 = 24" << endl;
		i = 6;
	}
	for (; i <= n; i += 2) 
	{
		printf("%d - %d = %d\n", i+1, i, 1);
		printf("%d * %d = %d\n", 24, 1, 24);
//		cout << i+1 << " - " << i << " = " << 1 << endl;
//		cout << 24 << " * " << 1 << " = " << 24 << endl;
	}

	return 0;
}  	

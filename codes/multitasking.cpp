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

int n, m, d;

int main () {
	cin >> n >> m >> d;
	
	cout << m * (m-1) / 2 << endl;
	
		for (int i = m; i >= 0; i --)
		{
			for (int j = 1; j < i; j ++)
			{
				if (!d)
					cout << j << " " << j+1 << endl;
				else
					cout << j+1 << " " << j << endl;
			}
		}
	
	return 0;
}  	

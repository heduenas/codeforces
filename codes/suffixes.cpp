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

int n, m;
int a, l;
int A[200100];
int D[200100];
int E[200100];

int main () {
	cin >> n >> m;
	scan(A, 0, n);
	
	for (int i = n-1, dif = 0; i >= 0; i --)
	{
		a = A[i];
		if (!D[a])
		{
			D[a] = 1;
			dif ++;
		}
		E[i] = dif;
	}
	
	for (int i = 0; i < m; i ++)
	{
		cin >> l;
		cout << E[l-1] << endl;
	}
	
	return 0;
}  	

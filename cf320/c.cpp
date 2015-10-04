#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

int n;
double A[200100];
double C[200100];
double Min[200100], Max[200100];

double test(double x)
{
	C[0] = A[0] + x;
	for (int i = 1; i < n; i ++)
	{
		C[i] = A[i] + C[i-1] + x;
	}
	
	Min[0] = Max[0] = 0;
	//Min[0] = min(0.0, Min[0]);
	//Max[0] = max(0.0, Max[0]);
	for (int i = 0; i < n; i ++)
	{
		Min[i] = min(Min[i-1], C[i]);
		Max[i] = max(Max[i-1], C[i]);
	}
	
	double ret = 0;
	
	for (int i = 0; i < n; i ++)
	{
		ret = max(ret, C[i] - Min[i]);
		ret = max(ret, Max[i] - C[i]);
	}
//	print(C, 0, n);
//	cout << endl;
//	print(Min, 0, n);
//	cout << endl;
//	print(Max, 0, n);
//	cout << endl;
//	cout << endl;
	return ret;
}

double ternary()
{
	double left, right, pv1, pv2;
	double val1, val2;
	left = -20000;
	right = 20000;
	
	for (int z = 0; z < 120; z ++)
	{
		pv1 = left + (right - left) / 3.0;
		pv2 = left + 2.0 * (right - left) / 3.0;
		
		val1 = test(pv1);
		val2 = test(pv2);
		
//	cout << pv1 << " " << val1 << endl;
//	cout << pv2 << " " << val2 << endl;
		if (val1 > val2)
		{
			left = pv1;
		}
		else
		{
			right = pv2;
		}
	}
//	cout << test(-5.75) << endl;
	return (val1+val2)/2.0;
}

int main()
{
	cin >> n;
	scan(A, 0, n);
		
	//cout << ternary() << endl;
	printf("%.10lf\n", ternary());
	
	return 0;
}



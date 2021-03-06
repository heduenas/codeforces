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

double a, b;

int main()
{
	//cin >> a >> b;
	scanf("%lf%lf", &a, &b);
	
	if (b > a)
	{
		//cout << -1 << endl;
		printf("-1\n");
		return 0;
	}
	if (a == b)
	{
		printf("%.10lf\n", a);
		return 0;
	}
	
	double opt1 = (a-b)/floor((a-b)/(2.0f*b));
	double opt2 = (a+b)/floor((a+b)/(2.0f*b));
	
	cerr << (a-b) << endl;
	
	printf("%.10lf\n", min(opt1, opt2)/2.0f);
	return 0;
	
	return 0;
}



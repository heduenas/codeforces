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
#include <cassert>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>

#define deb(x) cout << #x << " = " << x << endl;
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
char A[201000];
int ans;

int main()
{
	scanf("%d", &n);
	scanf("%s", A);
	
	ans = 1;
	for (int i = 1; i < n; i ++)
		ans += A[i] != A[i-1];	
	
	cout << min(n, ans+2);
	
	return 0;
}

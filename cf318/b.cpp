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
int A[200100];
int DPl[200100];
int DPr[200100];

int main()
{
	cin >> n;
	scan(A, 0, n);
	
	DPl[0] = DPl[n-1] = 1;
	DPr[0] = DPr[n-1] = 1;
	for (int i = n-2; i > 0; i--)
	{
		if (A[i] > DPr[i+1])
			DPr[i] = DPr[i+1]+1;
		else
			DPr[i] = A[i];
	}
	for (int i = 1; i < n-1; i++)
	{
		if (A[i] > DPl[i-1])
			DPl[i] = DPl[i-1]+1;
		else
			DPl[i] = A[i];
	}
	
	int ans = 1;
	for (int i = 0; i < n; i ++)
		ans = max(ans, min(DPl[i], DPr[i]));
	
	cout << ans << endl;
	
	return 0;
}



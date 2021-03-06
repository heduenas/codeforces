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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n, k;

int main()
{
	cin >> n >> k;

	bool turn = false;
	int done =  0;
	int left = 1;
	int right = n;
	while (done < k)
	{
		if (turn)
		{
			cout << right << " ";
			right --;
		}
		else
		{
			cout << left << " ";
			left ++;
		}
		turn = !turn;
		done ++;
	}
	if (turn)
	{
		while (left <= right)
		{
			cout << left++ << " ";
		}
	}
	else
	{
		while (left <= right)
		{
			cout << right-- << " ";
		}
	}

	return 0;
}



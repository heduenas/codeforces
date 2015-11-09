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

char M[10][10];

int minl = 10;
int minc;

int Verify(int y, int x)
{
	int dy = 1;
	if (M[y][x] == 'W')
		dy = -1;
		
	int ret = 0;
	while (ret == 0 or (y > 0 and y < 7))
	{
		y += dy;
		if (M[y][x] != '.')
			return 11;
		ret ++;
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 8; i ++)
		cin >> M[i];
		
	for (int i = 0; i < 8; i ++)
	{
		for (int j = 0; j < 8; j ++)
		{
			if (M[i][j] == '.')
				continue;
			int len = Verify(i, j);
			if ((len < minl) or (len == minl and M[i][j] == 'W'))
			{
				minl = len;
				minc = M[i][j] == 'B';
			}
		}
	}
	
	if (minc == 0)
		cout << "A" << endl;
	else
		cout << "B" << endl;

	return 0;
}



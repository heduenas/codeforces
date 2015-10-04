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

int t, B[10];
char str[1010];

int mini2()
{
	int maxidx = 0;
	for (int i = strlen(str)-1; i > 0; i --)
	{
		if (str[i] < str[maxidx])
			maxidx = i;
	}
	swap(str[maxidx], str[1]);
	int ret;
	sscanf(str, "%d", &ret);
	swap(str[maxidx], str[1]);
	return ret;
}

int mini()
{
	int maxidx = 0;
	for (int i = strlen(str)-1; i > 0; i --)
	{
		if (str[i] != '0' and str[i] < str[maxidx])
			maxidx = i;
	}
	swap(str[maxidx], str[0]);
	int ret;
	sscanf(str, "%d", &ret);
	swap(str[maxidx], str[0]);
	if (maxidx == 0 and strlen(str) > 1)
		return mini2();
	return ret;
}

int maxi2()
{
	int maxidx = 0;
	for (int i = strlen(str)-1; i > 0; i --)
	{
		if (str[i] < str[maxidx])
			maxidx = i;
	}
	swap(str[maxidx], str[strlen(str)-1]);
	int ret;
	sscanf(str, "%d", &ret);
	swap(str[maxidx], str[strlen(str)-1]);
	return ret;
}

int maxi()
{
	int maxidx = 0;
	for (int i = strlen(str)-1; i > 0; i --)
	{
		if (str[i] > str[maxidx])
			maxidx = i;
	}
	swap(str[maxidx], str[0]);
	int ret;
	sscanf(str, "%d", &ret);
	swap(str[maxidx], str[0]);
	if (maxidx == 0 and strlen(str) > 1)
		return maxi2();
	return ret;
}

int main()
{
	cin >> t;
	int caze;
	while (t--)
	{
		caze ++;
		cin >> str;
		cout << "Case #" << caze << ": " << mini() << " " << maxi() << endl;
	}
	return 0;
}



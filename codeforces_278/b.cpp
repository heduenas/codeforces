// monotonic queue

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

int n, s, l;
int A[100100];
int DP[100100];

deque<int> Qmin;
deque<int> Qmax;
deque<int> QDP;

int main()
{
	cin >> n >> s >> l;
	scan(A, 1, n+1);
	
	DP[0] = 0;
	int tail = 0;
	for (int i = 1; i <= n; i ++)
	{
		while (!Qmin.empty() and A[Qmin.back()] > A[i])
			Qmin.pop_back();
		Qmin.push_back(i);
		while (!Qmax.empty() and A[Qmax.back()] < A[i])
			Qmax.pop_back();
		Qmax.push_back(i);
		
		while (A[Qmax.front()] - A[Qmin.front()] > s)
		{
			if (Qmax.front() < Qmin.front())
			{
				tail = Qmax.front();
				Qmax.pop_front();
			} else
			{
				tail = Qmin.front();
				Qmin.pop_front();
			}
		}
		if (i-l >= 0)
		{
			while (!QDP.empty() and DP[QDP.back()] > DP[i-l])
				QDP.pop_back();
			QDP.push_back(i-l);
		}
		while (!QDP.empty() and QDP.front() < tail)
			QDP.pop_front();
			
		if (QDP.empty())
			DP[i] = 1 << 30; 
		else
			DP[i] = DP[QDP.front()] + 1;
	}
	
	cout << (DP[n]>=(1<<30)?-1:DP[n]) << endl;
	//print(DP, 0, n+1);

	return 0;
}

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<cassert>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

const int threshold = 150000;

int n, H[600100];
int S[600100], ss = 0;

vector<int> ans;

int main () {
	cin >> n;
	scan(H, 0, n);
	
	int rep = 0;
	do
	{
	
	for (int i = 0; i < n; i ++)
	{
		while ((ss > 0) and (H[i] > S[ss-2]))
		{
			if (S[ss-2] + S[ss-1] >= threshold)
			{
				ans.push_back(S[ss-3]);
			}
			ss -= 3;
			if (ss)
				S[ss-1] = max(S[ss-1], S[ss+2]);
		}
		
		if (!rep)
			S[ss ++] = i+1;
		else
			S[ss ++] = n-i;
		S[ss ++] = H[i];
		S[ss ++] = -H[i];
	}
	
	while (ss)
	{
		if (S[ss -2] >= threshold)
			ans.push_back(S[ss -3]);
		ss -= 3;
	}
	
	reverse(H, H+n);
	rep ++;
	} while (rep < 2);
	
	sort(ans.begin(), ans.end());
	
	bool first = true;
	for (int i = 0; i < ans.size(); i ++)
		if (i < ans.size() and ans[i] == ans[i+1])
		{
			if (!first)
				cout << " ";
			first = false;
			
			cout << ans[i];
			i ++;
		}
	cout << endl;
	
	return 0;
}  	

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

const long long mod = 1000000007;

int n = 0;
char str[100];
int D[10];
long long DP[11][101][12];

int toteven, totodd;

long long cb[120][120];

long long f(int idx, int oddc, int evenc, int val)
{
	if (idx == 10)
	{
		if (val == 0)
			return 1;
		else
			return 0;
	}
	
	if (DP[idx][oddc][val] == -1)
	{
		DP[idx][oddc][val] = 0;
		
		for (int odd = 0, even = D[idx]; odd <= D[idx]; odd ++, even --)
		{
			if (odd <= totodd - oddc - (idx == 0)
			and even <= toteven - evenc) 
			{
			    DP[idx][oddc][val] += 
			            (
				    f(idx+1, oddc + odd, evenc + even, (val + odd * idx + even * (10 * idx)) % 11)
				    * (( cb[totodd - oddc - (idx == 0)][odd] * cb[toteven - evenc][even] ) % mod)
				    ) % mod;
			    DP[idx][oddc][val] %= mod;
			} 
		}
	}
	return DP[idx][oddc][val];
}

int main () 
{
	memset(DP, -1, sizeof DP);
	for (int i = 0; i <= 110; i ++)
		for (int j = 0; j <= 110; j ++)
			if (j == 0 or i == j)
				cb[i][j] = 1;
			else
				cb[i][j] = (cb[i-1][j] + cb[i-1][j-1]) % mod;

	cin >> str;
	n = strlen(str);
	for (char *chr = str; *chr; chr ++)
		D[*chr - '0'] ++;
		
	toteven = n / 2;
	totodd = (n + 1) / 2;
		
	cout << f(0, 0, 0, 0) << endl;

	return 0;
}  	

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

int a, b;

int digsum(int num)
{
	int ans = 0;
	while (num)
	{
		ans += num % 10;
		num /= 10;
	}
	return ans;
}

int sum(int num) 
{
	int ret = 0;
	int pot = 1;
	int num2 = num;
	while (num2)
	{
		ret += ((num2%10) * (num / (pot * 10) + 1)) * pot;
		pot *= 10;
		num2 /= 10;
	}
	return ret;
}

int main () {
	cin >> a >> b;

	int ans = 0;
	for (int i = a; i <= b; i ++)
		ans += digsum(i);

	cout << ans << endl;

	ans = 0;
	ans = sum(b) - sum(a);
	cout << ans << endl;

	return 0;
}  	

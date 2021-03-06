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

int n;
char str[1000100];
int ak[1000100];

int total_l;
int total_r;
int total_s;

int main () {
	cin >> str;
	n = strlen(str);
	
	for (int i = 0; i < n; i ++)
	{
		if (str[i] == '(')
			total_l ++;
		else if (str[i] == ')')
			total_r ++;
		else
			total_s ++;
	}
	
	for (int i = 0; i < n; i ++)
	{
		if (str[i] == '#')
		{
			total_s --;
			ak[i] = 1;
			total_r ++;
			if (total_s == 0)
				ak[i] += -total_r+total_l;
		}
	}
	
	int count = 0;
	for (int i = 0; i < n; i ++)
	{
		if (str[i] == '(')
			count ++;
		else if (str[i] == ')')
			count --;
		else 
		{
			count -= ak[i];
			if (ak[i] <= 0)
			{
				cout << -1 << endl;
				return 0;
			}			
		}
		if (count < 0)
		{
			cout << -1 << endl;
			return 0;
		}	
	}
	
	for (int i = 0; i < n; i ++)
		if (ak[i] > 0)
			cout << ak[i] << endl;

	return 0;
}  	

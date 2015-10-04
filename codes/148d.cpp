#include<stdio.h>
#include<iostream>
#include<iomanip>
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

bool mem[2][1010][1010];
double DP[2][1010][1010];

double f (bool turn, int w, int b) {
	if (w < 0 or b < 0)
		return 0.0;
		
	if (mem[turn][w][b] == false) {
		mem[turn][w][b] = true;
		double &opt = DP[turn][w][b];
		if (!turn) {
			if (w + b == 0)
				opt = 0.0;
			else
				opt = (double)(w) / (w+b) + ((double)(b) / (w+b)) * f (!turn, w, b-1);
		} else {
			if (w + b <= 2)
				opt = 0.0;
			else {
				opt = ((double)(w) / (w+b-1)) * f (!turn, w-1, b-1);
				opt += ((double)(b-1) / (w+b-1)) * f (!turn, w, b-2);
				opt *= (double)(b) / (w+b);
			}
		}
	}
	return DP[turn][w][b];
}

int w, b;

int main () {
	cin >> w >> b;
	memset (mem, false, sizeof mem);
	cout << setprecision (9) << f(0, w, b) << endl;
	return 0;
}  	

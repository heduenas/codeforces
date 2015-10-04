#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int a, b, n;
char str[110];
bool A[210][210];
int totx, toty;

bool mod0 (int a, int b) {
	if (b == 0) {
		return a == 0;
	}
	return (a % b) == 0;
}

int div2 (int a, int b, int c = 0, int d = 1) {
	if (a == 0 and b == 0)
		return c / d;
	return a / b;
}

int main () {
	cin >> a >> b;
	cin >> str;
	n = strlen (str);
	for (int i = 0; i < n; i ++) {
		A[totx+100][toty+100] = true;
		if (str[i] == 'U') {
			toty ++;
		} else if (str[i] == 'D')
			toty --;
		else if (str[i] == 'R')
			totx ++;
		else
			totx --;
	}
	
	bool ans = false;
	if (totx == 0 and toty == 0)
		ans = A[a + 100][b + 100];
	else
	for (int i = -100; i <= 100; i ++) {
		for (int j = -100; j <= 100; j ++) {
			if (A[i+100][j+100] == false)
				continue ;
				
			int ap = a - i;
			int bp = b - j;
			if (mod0(ap, totx) and mod0(bp, toty) and (div2 (ap, totx, bp, toty) == div2 (bp, toty, ap, totx)) and (div2 (ap, totx, bp, toty) >= 0)) {
				ans = true;
				break;
			}
		}
		if (ans)
			break;
	}
	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
		
	//for (int i = 0; i < n; i ++) {
	//}	
	return 0;
}

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
int P[1000010];

int main () {
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int p = i;
		int it = 2;
		while (it <= n) {
			int oldit = it;
		
			p -= 1 - min((p %oldit)/2, n-oldit);
			
			if ((p+it)%it == it-1) {
				if ((p+1) / it == n / it)
					p = n-1;
				else
					p += it;
			}
			
			it ++;
			
			/*if (p / it == 0) {
				it += min(p+1, n-it);
				p -= min(p+1, n-oldit);
			} else {*/
				it += min((p % it)/2, n-it);
				//p -= 1 + min((p %oldit)/2, n-oldit);
//			}
		}
		P[p] = i;
	}
	
	for (int i = 0; i < n; i ++)
		cout << P[i] + 1 << " ";
	
	return 0;
} 

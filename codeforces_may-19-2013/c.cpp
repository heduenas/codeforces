#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int n, A[1000000], ans;
map<int, int> M;

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &A[i]);
		
		if (M.count (A[i]) == 0)
			M[A[i]] = 1;
		else
			M[A[i]] ++;
	}
	
	for(map<int, int>::iterator it = M.begin(); it != M.end(); ++ it)
   {
   		if ((*it).second > 1) {
			M[(*it).first + 1] += (*it).second / 2;
			M[(*it).first] = (*it).second % 2;
		}
   }
	
	
	bool first = true;
	int prev = 0;
	for(map<int, int>::iterator it = M.begin(); it != M.end(); ++ it)
   {
   		if ((*it).second == 0)
   			continue ;
   			
   		if (first) {
   			ans = (*it).first;
   		} else {
   			ans += (*it).first - prev - 1;
   		}
 
 		prev = (*it).first;
		first = false;
   }

	printf ("%d\n", ans);
	
	return 0;
}

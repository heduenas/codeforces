#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << _z)
using namespace std;

int n;
pair<int, int> P[100010];
pair<int, int> Q[100010];

long long B[2010][2010];
long long ans = 0;

int main () {
	cin >> n;
	for (int i =0 ; i < n; i ++)
		cin >> P[i].first >> P[i].second;
		
	sort(P, P + n);
	
	Q[0].first = P[0].second;
	Q[0].second = 0;
	for (int i = 1, rank = 0; i < n; i ++) {
		if (P[i].first != P[i-1].first)
			rank ++;
		Q[i].first = P[i].second;
		Q[i].second = rank;
	}
	
	sort(Q, Q + n);
	for (int i = 0, rank = -1; i < n; i ++) {
		if (rank == -1 or Q[i].first != Q[i-1].first)
			rank ++;
		B[map(rank)][
	}
   
    return 0;
}   

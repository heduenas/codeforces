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
#define mp make_pair

using namespace std;

const int lim =400100;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

const long long mod = 1000000007;

long long a, b;

int main()
{
    cin >> a >> b;
    
    long long ans;
    ans = (b * (b-1)) / 2;
    ans %= mod;
    ans *= ((( b * ((( a * (a+1)) / 2) % mod)) % mod) + a) % mod;
    ans %= mod;
    
    cout << ans << endl;
    
    return 0;
}


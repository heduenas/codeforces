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

int n, k;

int main()
{
    cin >> n >> k;
    
    cout << (6 * n - 1) * k << endl;
    for (int i = 1; i <= (6 * n - 1); i ++)
    {
    	if ((i % 6) != 4
    	and (i % 6) != 0)
    		cout << i * k << " ";
    	
    	if ((i % 6) == 0)
    		cout << endl;
    }
    
    return 0;
}
 

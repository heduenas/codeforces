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
#include <cassert>
#include <string.h>
#include <vector>
#include <set>
#include <list>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
#include <iomanip>      // std::setprecision

#define deb(x) cout << #x << " = " << x << endl;
#define print(Z,a,b) for (int __z = a; __z < b; __z ++) cout << Z[__z] << " ";
#define scan(Z,a,b) for (int __z = a; __z < b; __z ++) cin >> Z[__z];
#define bit(_z) (1ll << (_z))
#define rep(__z,__Z) for(int __z = 0; __z < __Z ; __z++ )
#define all(__z) __z.begin(),__z.end()

#define par pair<int, int>
#define p1 first
#define p2 second

#define eps = 1e-6

using namespace std;

int n;
double ax, ay, bx, by, tx, ty;
double DA[200100], DB[200100];
double ans;

double d(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main()
{
	int cA1 = 0, cA2 = 0, cB1 = 0, cB2 = 0;
	double totdist;

	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		double x, y;
		cin >> x >> y;
		DA[i] = -d(ax, ay, x, y) + d(tx, ty, x, y);
		DB[i] = -d(bx, by, x, y) + d(tx, ty, x, y);
		totdist += 2.0 * d(tx, ty, x, y);

		if (DA[cA2] < DA[i]) {
			cA2 = i;
			if (DA[cA2] > DA[cA1]) {
				swap(cA1, cA2);
			}
		}
		if (DA[cB2] < DB[i]) {
			cB2 = i;
			if (DB[cB2] > DB[cB1]) {
				swap(cB1, cB2);
			}
		}
	}

	ans = totdist;
	if (n == 1 or DA[cA1] < 0.0 or DB[cB1] < 0.0) {
		ans -= max(DB[cB1], DA[cA1]);
	} else if (cA1 != cB1) {
		ans -= DA[cA1];
		ans -= DB[cB1];
	} else {
		ans -= max(DA[cA1] + DB[cB2], DA[cA2] + DB[cB1]);
	}

	printf("%.12lf", ans);

	return 0;
}


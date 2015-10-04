#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
     
using namespace std;
     
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
     
typedef long long int64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pii64;
   
const int INF = 1000 * 1000 * 1000;
const int MODULO = 1000*1000*1000 + 7;
const int MAXN = 1005;

int n, m;
char c[MAXN][MAXN];
bool answer[MAXN];

void rec(int column, int first, int second) {
    if (column == m) return;
    bool ok = true;
    char cur = c[first][column];
    for (int i = first; i <= second; i++)
        if (cur > c[i][column])
            ok = false;
        else
            cur = c[i][column];
    if (!ok) {
        answer[column] = true;
        rec(column + 1, first, second);
    }
    else {
        int i;
        for (i = first; i <= second; ) {
            int k = i;
            while (k + 1 < n && c[i][column] == c[k + 1][column])
                k++;
            rec(column + 1, i, k);
            i = k + 1;        
        }
    }
}

int main() { 
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }

    rec(0, 0, n - 1);
    int cnt = 0;
    for (int i = 0; i < m; i++)
        if (answer[i])
            cnt++;

    cout << cnt;

    return 0;
}

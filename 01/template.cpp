/// Макросы и константы
/// -------------------
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <complex>
#include <list>
#include <deque>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double PI = acos(-1.0);
const double eps = 1e-12;
const int INF = (1 << 30) - 1;
const ll LLINF = ((ll)1 << 62) - 1;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define XX first
#define YY second
#define all(x) x.begin(),x.end()
#define fill(a, x) memset(a, x, sizeof(a));
#define foreach(i, t) for(typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define forn(i, s, n) for(int i = s; i < (int)n; ++i)
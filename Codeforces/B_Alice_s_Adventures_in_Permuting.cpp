#include <bits/stdc++.h>
#include <numeric>
#include <random>
#include <cstdint>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define all(v) v.begin(), v.end()
#define left id << 1
#define right id << 1 | 1
#define sz(x) (int)x.size()
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int lg2 = 20;
const int N = 2010;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

template <class T>
bool ckmin(T &a, T b) {
	if (a > b)
		return (a = b);
	return 0;
}

template <class T>
bool ckmax(T &a, T b) {
	if (a < b)
		return (a = b);
	return 0;
}

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res *= a;
		b >>= 1;
		a *= a;
	}
	return res;
}

void add(ll &a, ll b) {
	a += b;
	if (a >= mod) 
		a -= mod;
}

void sub(ll &a, ll b) {
	a -= b;
	if (a < 0) 
		a += mod;
}

void solve() {
	ll n, b, c; cin >> n >> b >> c;
    if (b == 0) {
        if (c >= n) {
            cout << n << '\n'; 
        } else
        if (c == n - 1 || c == n - 2) {
            cout << n - 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    ll i = ceil(1.0 * (n - c) / b);
    ///cout << i << '\n';
    if (i < 0) {
        cout << n << '\n';
    } else 
        cout << n - i << '\n';
}

/*
	5 4 7
    1 2  3  4  5
    7 11 15 19 23
    7 11 15 19 0
    7 11 15 1 0
    4 3 2 1 0
    n
    b != c -> ans = n (?)

    3 0 1
    1 2 0
    3 0 2
    2 1 0

    5 1 0
    0 1 2 3 4
    b = 1 && c = 0 -> ans = 0

    5 12 0
    0 12 24 36 48
    0 1 2 3 4 -> ans = n - 1;
    b > n && c = 0

    5 0 1
    1 1 1 1 1
    1 4 3 2 0
    b = 0 && c < n - > ans = n - 1 

    5 5 5 5 5 -> n 

    5 0 0 -> -1
    0 1 0 0 0
0 1 2 3 4
    5 1 2 -> b < c 
    2 3 4 5 6
    2 3 4 1 0
 b * i + c < n -> n - i
    5 1 1 -> b == c n -> 1
    1 2 3 4 5
    1 2 3 4 0 
100 2 1
100 - 1 / 2
50
    (n - c) / b;
    5 1 0
    5 / 12 -> n -  1 


    2 0 0
    0 1

    3 0 0
    0 0 2

    2 2 2 2 2
    0 1 2 4 2 
*/

int32_t main() {

	// if (fopen("input.inp", "r")) {
	// 	freopen("input.inp", "r", stdin);
	// 	freopen("output.out", "w", stdout);
	// }
	
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);


	int tc; cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}

/*
	nice bin string
	1 must go with 0
	0 must go with 1
 */
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
#define DEBUG cout << "TESTCASE " << tc << ": ";

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
	int n; cin >> n;
    vector<int> L(n + 1, inf), R(n + 1, -inf);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        --x;
        ckmin(L[x], i);
        ckmax(R[x], i);
    }

    vector<int> f(n + 1, 0);
    int l = n, r = -1;
    for (int i = 0; i < n; ++i) {
        ckmin(l, L[i]);
        ckmax(r, R[i]);
        if (r - l <= i) {
            int ll = max(0, r - i);
            int rr = min(n - 1, l + i);
            ++f[ll];
            if (rr < n - 1) {
                --f[rr + 1];
            }
        }
        // cout << l << ' ' << r << '\n';
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << f[i] << ' ';
    // }

    for (int i = 1; i < n; ++i) {
        f[i] += f[i - 1];
    }
    int ans = count(all(f), n);
    cout << ans << '\n';
}

/*
	6
    1 2 3 4 5 6
    6 3 3 3 5 5

    6
    5 6 4 1 4 5
      5 4 1 2 3

    10
    5 4 4 2 2 3 4 4 4 5

    10 
    
    7 3 7 3
    3 2 4 1
    10 
    10 10 10 10 4 4 5 10 10 10

    

    find the smallest sub interval
    called the value of this interval is x
    how long this interval is should be to x
    if there's an element = x, with distance larger than x
    then there's no way to win
    if the interval length < value of x -> pick j more as beginning. 
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
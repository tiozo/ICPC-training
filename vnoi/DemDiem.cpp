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

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}

const int lg2 = 20;
const int N = 2010;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f;
const double esp = 1e-9;

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

struct Point {
    ll x, y, w;
    ll val = 0;
    bool operator < (const Point &a) const {
        return val < a.val;
    }
};

double sqr(ll x) {
    return double(1) * x * x;
}

void solve() {
	int n, q; cin >> n >> q;
    vector<Point> a(n);
    for (auto &e: a) {
        cin >> e.x >> e.y >> e.w;
    }
    for (auto &e: a) {
        e.val = sqr(e.x) + sqr(e.y);
    }
    auto cmp = [&](Point a, Point b) {
        return a.val < b.val;
    };
    sort(all(a));

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] += prefix[i - 1] + a[i - 1].w;
    }

    while (q--) {
        Point r; cin >> r.val;
		r.val = sqr(r.val);
        int it = upper_bound(all(a), r, cmp) - a.begin();
		// cout << it << '\n';
		if (it == 0 && a[it].val - r.val > esp) {
			cout << 0 << '\n';
		} else 
        	cout << prefix[it] << '\n';
    }
}

/*
	
*/

int32_t main() {

	// if (fopen("input.inp", "r")) {
	// 	freopen("input.inp", "r", stdin);
	// 	freopen("output.out", "w", stdout);
	// }
	
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);


	// int tc; cin >> tc;
	// while (tc--) {
		solve();
	// }

	return 0;
}

/*
	nice bin string
	1 must go with 0
	0 must go with 1
 */
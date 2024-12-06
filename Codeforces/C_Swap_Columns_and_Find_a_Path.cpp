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
#define DEBUG cout << "TESTCASE " << tc << ": \n";

const int lg2 = 20;
const int N = 2010;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first + a.second < b.first + b.second;
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
    vector<pair<int, int>> a(n);
    for (auto &e: a) cin >> e.first;
    for (auto &e: a) cin >> e.second;
    // sort(all(a), cmp);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += max(a[i].first, a[i].second);
    }
	int mx_min = -inf;
	for (int i =  0; i < n; ++i) {
		ckmax(mx_min, min(a[i].second, a[i].first));
	}
    cout << res + mx_min << '\n';
}

/*
	0 1 2
        2 -3 2 4 
*/

int32_t main() {

	if (fopen("input.inp", "r")) {
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	}
	
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);


	int tc; cin >> tc;
	while (tc--) {
        // DEBUG
		solve();
	}

	return 0;
}

/*
	nice bin string
	1 must go with 0
	0 must go with 1
 */
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
	vector<int> cnt(1e5 + 100, 0);
	int mxVal = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		ckmax(mxVal, x);
		++cnt[x];
	}
	vector<int> g(mxVal + 100, 0), h(mxVal + 100, 0);
	/// numbers of value c.
	vector<int> up(mxVal + 100, 0);
	int pre = 0;
	for (int i = mxVal; i >= 0; --i) {
		up[i] = pre;
		pre += cnt[i];
	}
	// cerr << mxVal;
	ll ans = 0;
	vector<ll> dp(mxVal + 10, 0);
	for (int i = mxVal; i >= 1; --i) {
		// cerr << i << ' ';
		ll pre1 = 0, pre2 = 0;
		for (int j = i; j <= mxVal; j += i) {
			// cerr << j << ' ';
			pre2 += (pre1 * cnt[j] + 1ll * cnt[j] * (cnt[j] - 1) / 2) * up[j];
			pre2 += 1ll * cnt[j] * (cnt[j] - 1) * (cnt[j] - 2) / 6;
			pre2 += pre1 * cnt[j] * (cnt[j] - 1) / 2;
			dp[i] -= dp[j];
			pre1 += cnt[j];
		}
		// cerr << '\n';
		dp[i] += pre2;
		ans += dp[i] * i;
	}
	cout << ans << '\n';
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
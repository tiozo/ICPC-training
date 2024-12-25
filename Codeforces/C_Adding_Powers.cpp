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
    int n, k; see(n, k);
    vector<ll> a(n);
    /// log100(1e16) ~~ 8 -> the K is somewhat nulsense ?
    /// the largest step is max(logk(a[i]))
    for (auto &e: a) cin >> e;
    
    sort(all(a));
    auto logk = [&](ll val) {
        ll res = 0;
        while (val) {
            val /= k; ++res;
        }
        return res;
    };
    bool flag = false;
    int maxBits = logk(a.back()) + 1;
    vector<int> vis(maxBits + 1, 0);
    for (int i = 0; i < n; ++i) {
        int times = logk(a[i]);
        int pos = 0; 
        while (a[i]) {
            vis[pos++] += a[i] % k;
            a[i] /= k; 
        }
    }
    for (int i = 0; i < maxBits; ++i) {
        if (vis[i] > 1) {
            flag = true;
        }
    } 
    if (flag) {
        cout << "NO\n"; 
    } else {
        cout << "YES\n";
    }
    // cout << 59058 % 9 << '\n';
}

/*
    k = 100
	1 1 1 1

    3 9
    0 59049 810

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
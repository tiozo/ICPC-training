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

void mul(ll &a, ll b, ll mod = mod) {
    a %= mod; b %= mod;
    a *= b; a %= mod;
}

void solve() {
	int n; cin >> n;
    ll prod = 1;
    vector<int> ans;
    for (int i = 1; i < n - 1; ++i) {
        if (__gcd(i, n) == 1) {
            ans.push_back(i);
            mul(prod, i, n);
        }
    }
    // cout << prod << '\n';
    if (prod == n - 1) ans.push_back(n - 1);
    cout << sz(ans) << '\n';
    for (int e: ans) cout << e << ' ';
}

/*
	(a + b) % c = a % c + b % c
    (a * b) % c = a % c * b % c 
    max value = 1 % n 
    -> 1, (n + 1), 2 (n + 1), 3 (n + 1), ... 
    the product in need is the sequence above
    but the sequence is only (1 -> n - 1)
    -> either 1, or (n + 1)
    8 -> 2, 4.

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
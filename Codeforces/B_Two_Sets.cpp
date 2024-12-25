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

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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

vector<int> par;
int find(int x) {
	return (par[x] == x ? x : par[x] = find(par[x]));
}

void solve() {
	// cout << (1 | 2) << '\n';
	int n, x, y; see(n, x, y);
	par.clear(), par.resize(n + 1, 0);
	vector<int> a(n), vis(n, 0);
	unordered_map<int, int, chash> exist;
	int idx = 0;
	for (int &e: a) cin >> e, exist[e] = idx, idx++;
	// cerr << "DEAD";
	for (int i = 0; i < n; ++i) {
		par[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		if (exist.find(x - a[i]) != exist.end()) {
			par[find(exist[x - a[i]])] = find(i); vis[i] |= 1; 
		}
		if (exist.find(y - a[i]) != exist.end()) {
			par[find(exist[y - a[i]])] = find(i); vis[i] |= 2; 
		}
		// put(vis[i]);
	}
	vector<int> res(n, 3);
	for (int i = 0; i < n; ++i) res[find(i)] &= vis[i];
	for (int i = 0; i < n; ++i) if (res[i] == 0) {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << ((res[find(i)]&1) == 0) << ' ';
	}
}

/*
	note: 
        + if x is in A then a - x must be exist
            to also be in A
    a = 4, b = 2
	0 2 4 1 1
	YES
	1 1 1
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
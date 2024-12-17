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

vector<vector<int>> adj;
vector<int> vis;

void dfs(int u) {
    vis[u] = true;
    for (auto v: adj[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}

void solve() {
    int n; see(n);
    adj.clear(); adj.resize(n + 1);
    vis.clear(); vis.resize(n + 1, 0);
	vector<int> a(2 * n);
    for (int &e: a) see(e);
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        adj[a[i]].push_back(a[i + n]);
        adj[a[i + n]].push_back(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        add(ans, ans);
        dfs(i);
    }
    cout << ans << '\n';
}

/*
	no numbers on the same column or row are the same
    able to swap the numbers in any column
    the number of possible solved configurations 
    of the puzzle 
    he could achieve from an initial 
    solved configuration
    by swapping numbers in a column.
    
    3 8 7 5 1 2 4 6
    2 6 5 1 4 3 7 8

    3 2 1 4
    1 4 2 3

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
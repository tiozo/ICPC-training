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

vector<vector<int>> ans;

void dfs(vector<int> &a, const int n, const int m) {
    int sz = sz(a);
    if (sz == n) {
        ans.push_back(a);
        return;
    }
    for (int i = (sz == 0 ? 1 : a.back() + 10); i <= m - 10 * (n - sz - 1); ++i) {
        vector<int> nxt = a;
        nxt.push_back(i);
        dfs(nxt, n, m);
    }
}

void solve() {
	int n, m; cin >> n >> m;
    vector<int> a;
    dfs(a, n, m);
    cout << sz(ans) << '\n';
    for (auto &v: ans) {
        for (int &e: v) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}

/*
	M - 1
    M - 2
    M - 3
    ...... 
    M - x 
    - a[N - 1] + a[N] 
    != 10;

    23 / 10
    
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
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

struct DSU {
private: 
	vector<int> parent;
	vector<int> sizes;

public:
	DSU(int size = 10) {
		parent.resize(size + 1);
		sizes.resize(size + 1);
		for (int i = 1; i <= size; ++i) {
			parent[i] = i;
			sizes[i] = 1;
		}
	};

	int find(int x) {
		return parent[x] == x ? x : (parent[x] = find(parent[x]));
	}

	bool join(int u, int v) {
		int uu = find(u);
		int vv = find(v);
		if (uu == vv) return false;
		if (sizes[uu] < sizes[vv]) swap(uu, vv);
		sizes[uu] += sizes[vv];
		parent[vv] = uu;		
		return true;
	}
};

void solve() {
	int n, m; cin >> n >> m;
    vector<DSU> Color(m + 1, DSU(n + 10));
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        Color[c].join(u, v);
    }
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            if (Color[i].find(u) == Color[i].find(v)) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
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
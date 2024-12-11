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
const int N = 5e5 + 100;
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

/// @brief  template off orzdevinwang
/// @tparam N 
template < int N > struct stlca {
	int n;
	int ehd[N], ev[N * 2], enx[N * 2], eid;
	void Eadd(int u, int v) {
		enx[++eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
	}
	void add(int u, int v) {
		Eadd(u, v);
		Eadd(v, u);
	}
	/// @brief q = current depth of x LCA tree
    ///        fa = father of node x
    ///        dep = dep of node x of normal tree.

	int q[N], fa[N], dep[N], top;
	int cs[20][N];
	void dfs1(int x) {
		++top, cs[0][q[x] = top] = fa[x];
		for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) 
			dep[ev[i]] = dep[x] + 1, fa[ev[i]] = x, dfs1(ev[i]);
	}
	inline int cmin(int &x, int &y) {
		return dep[x] < dep[y] ? x : y;
	}
	int lca(int l, int r) {
		if(l == r) return l;
		l = q[l], r = q[r];
		if(l > r) swap(l, r);
		++l;
		int p = __lg(r - l + 1);
		return cmin(cs[p][l], cs[p][r - (1 << p) + 1]);
	}
	inline int dis(int x, int y) {
		return dep[x] + dep[y] - 2 * dep[lca(x, y)];
	}
	void mk(int xn) {
		n = xn, dfs1(1);
		for (int i = 1; i <= 19; ++i) for (int j = 1; j <= top - (1 << i) + 1; ++j) 
			cs[i][j] = cmin(cs[i - 1][j], cs[i - 1][j + (1 << (i - 1))]);
	}
	void clear() {
		for (int i = 1; i <= n; ++i) 
            ehd[i] = 0, fa[i] = 0;
		top = 0, n = 0, eid = 0;
	}
} ;
stlca < N > st;

vector<int> cnt[N];
void solve() {
	int n; cin >> n;
    st.clear();
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        st.add(u, v);
    }
    st.mk(n);
    for (int i = 1; i <= n; ++i){
        cnt[st.dep[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        sort(all(cnt[i]), [&](int u, int v) {
            return st.q[u] < st.q[v];
        });
        int sum = 0;
        for (int j = 0; j < sz(cnt[i]); ++j) {
            sum += st.dep[cnt[i][j]];
            if (j) sum -= st.dep[st.lca(cnt[i][j], cnt[i][j - 1])];
        }
        ckmax(ans, sum);
    }
    cout << n - ans - 1 << '\n';
	for (int i = 0; i <= n + 1; ++i) {
		cnt[i].clear();
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
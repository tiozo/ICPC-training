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

int sumDigit(int x) {
    int res = 0;
    while (x) {
        int tmp = x % 10;
        res += tmp; x /= 10;
    }
    return res;
}

struct Segtree {
    // static const int N = 1e5 + 10;
    int size = 0;
    vector<ll> lazy, tree;
    #define left id * 2
    #define right id * 2 + 1
    Segtree(int n) {
        size = n;
        n += 100;
        lazy.resize(4 * n, 0);
        tree.resize(4 * n, 0);
    }
    void shift(int id) {
        lazy[left] += lazy[id];
        lazy[right] += lazy[id];
        //tree[id] += lazy[id];
        tree[left] += lazy[id];
        tree[right] += lazy[id];
        lazy[id] = 0; 
    }
    // void modify(int id) {
    //     tree[id] = max()
    // }
    void build(int id, int l, int r, const vector<int> & a) {
        if (l > r) return;
        if (l == r) {
            // cout << a[l] << ' ';
            tree[id] = a[l];
            return;
        }
        int mid =  l + (r - l) / 2;
        build(left, l, mid, a);
        build(right, mid + 1, r, a);
        tree[id] = max(tree[left], tree[right]);
    }
    void build(const vector<int> &a) {
        build(1, 1, size, a);
    }
    void update(int id, int l, int r, int u, int v, int val) {
        if (l > r || l > v || r < u) return;
        if (u <= l && r <= v) {
            tree[id] += val;
            lazy[id] += val;
            return;
        }
        shift(id);
        int mid = l + (r - l) / 2;
        update(left, l, mid, u, v, val);
        update(right, mid + 1, r, u, v, val);
        tree[id] = max(tree[left], tree[right]);
    }
    ll get(int id, int l, int r, int u, int v) {
        if (u > r || l > v || l > r) return -(1e9 + 7);
        if (u <= l && r <= v) {
            /// if want to do problems with number of times update
            // return lazy[id];
            return tree[id];
        }
        shift(id);
        int mid = l + (r - l) / 2;
        return max(get(left, l, mid, u, v),
                   get(right, mid + 1, r, u, v));
    }
    void update(int u, int v, int val) {
        update(1, 1, size, u, v, val);
    }
    ll get(int u, int v) {
        return get(1, 1, size, u, v);
    }
};

void solve() {
	int n, m; cin >> n >> m;
    Segtree st(n); 
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n + 1, 1);
    st.build(b);
    while (m--) {
        int type; cin >> type;
        --type;
        if (type) {
            int x; cin >> x;
            int res = a[x], times = min(st.get(x, x), 3ll);
            while (times--) {
                res = sumDigit(res);
            }
            cout << res << '\n';
        } else {
            int l, r; cin >> l >> r;
            st.update(l, r, 1);
        }
    }
    
}

/*
	6420 9
    6 + 4 + 2

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
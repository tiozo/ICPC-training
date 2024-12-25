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
int mexVal;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int u) {
    vis[u] = mexVal++;
    for (auto v: adj[u]) {
        if (vis[v] != -1) continue;
        dfs(v); 
    }
    unordered_map<int, int> cnt;
    for (auto v: adj[u]) {
        ++cnt[vis[v]];
    }
    for (int i = 0; i <= sz(adj); ++i) {
        if (cnt.find(i) == cnt.end()) {
            vis[u] = i; return;
        }
    }
}

void solve() {
	int n; cin >> n;
    adj.clear(), adj.resize(n + 10);
    vis.clear(), vis.resize(n + 10, -1);
    mexVal = 0;
    int x, y; see(x, y);
    addEdge(x, y);
    vector<int> deg(n + 1, 2);
    deg[x]++, deg[y]++;
    for (int i = 1; i <= n; ++i) {

        if (i > 1 && i < n) {
            addEdge(i, i + 1);
            addEdge(i, i - 1);
        } else {
            if (i == 1) {
                addEdge(i, n);
                addEdge(i, i + 1);
            } else {
                addEdge(i, 1);
                addEdge(i - 1, i);
            }
        }
    }
    int u = 1, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (ckmax(cnt, deg[i])) {
            u = i;
        }
    }
    dfs(u);
    for (int i = 1; i <= n; ++i) {
        cout << vis[i] << ' ';
    }
    cout << '\n';
}

/*
	n, x, y 
    f[i] is friend with the ith dragon
    0 1 2 3 4 5 6 7
    7 = 1 
    0 = 6

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
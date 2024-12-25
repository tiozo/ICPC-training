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

struct GoodSet {
    unordered_map<int, int, chash> mp;
	int size, k;
	GoodSet() {};
	GoodSet(int bitLen = 0) {
		k = bitLen; 
		size = 0;
	}
	
	void insert(int x, int c = 1) {
		mp[x] += c;
		size += c;
	}

	void erase(int x) {
		if (mp.find(x) != mp.end()) {
			if (mp[x] == 1) 
				mp.erase(x);
			else 
				--mp[x];
		}
		--size;
	}

	void merge(const GoodSet &a) {
		for (auto [x, c]: a.mp) {
			insert(x, c);
		}
	}

	bool isGood() {
		return sz(mp) == (1 << k);
	}

	int get() {
		if (isGood()) return size;
		return 0;
	}
};

struct maxSet {
	map<int, int> cnt;
	maxSet() {}
	void insert(int x) {
		++cnt[x];
	} 
	void erase(int x) {
		if (cnt.find(x) != cnt.end()) {
			if (cnt[x] == 1) cnt.erase(x);
			else --cnt[x];
		}
	}
	int get() {
		return cnt.rbegin() -> first;
	}
};

struct DSU {
	int n, k; 
	vector<int> par;
	vector<GoodSet> cmp;
	maxSet goodLen;
	DSU() {}
	DSU(int n, int k): n(n), k(k) {
		par.resize(n + 1, -1);
		cmp.resize(n + 1, GoodSet(k));
		for (int i = 0; i <= n; ++i) {
			goodLen.insert(cmp[i].get());
		}
	}

	int find(int u) {
		return (par[u] == -1 ? u : par[u] = find(par[u]));
	}

	bool join(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		goodLen.erase(cmp[u].get());
		goodLen.erase(cmp[v].get());

		if (cmp[u].mp.size() < cmp[v].mp.size()) {
			cmp[u].mp.swap(cmp[v].mp);
			swap(cmp[u].size, cmp[v].size);
		}
		cmp[u].merge(cmp[v]);
		cmp[v].mp.clear();

		goodLen.insert(cmp[u].get());
		par[v] = u;
		return true;
	}

	void update(int u, int x, bool insert = true) {
		u = find(u); 
		goodLen.erase(cmp[u].get());
		if (insert) cmp[u].insert(x);
		else cmp[u].erase(x);
		goodLen.insert(cmp[u].get());
	}
}; 

void solve() {
	int n, q; see(n, q);
	vector<ll> a(n);
	for (auto &e: a) cin >> e;
	vector<pair<int, int>> queries(q);
	for (auto &[f, s]: queries) 
		see(f, s), a[--f] += s;

	vector<DSU> f(log2(n) + 1);
	maxSet se;

	for (int k = 0; (1 << k) <= n; ++k) {
		f[k] = DSU(n, k);
		for (int i = 0; i < n; ++i) {
			if (a[i] < (1 << k)) 
				f[k].update(i, a[i]);
			// cerr << f[k].cmp[i].size << ' ' << k << '\n';
		}
		// cerr << ' ' << '\n';
		for (int i = 1; i < n; ++i) {
			if (a[i] < (1 << k) && a[i - 1] < (1 << k)) {
				f[k].join(i - 1, i);
			}
		}
		se.insert(f[k].goodLen.get());
	}
	
	reverse(all(queries));
	vector<int> ans;
	for (auto [i, sub]: queries) {
		ans.push_back(se.get());
		// int i = queries[qid].first, sub = queries[qid].second;
		// cerr << i << ' ' << sub << " REAL ?" << '\n';
		for (int k = 0; (1 << k) <= n; ++k) {
			se.erase(f[k].goodLen.get());

			if (a[i] < (1 << k)) f[k].update(i, a[i], false);
			if (a[i] - sub < (1 << k)) f[k].update(i, a[i] - sub);

			if (a[i] >= (1 << k) && a[i] - sub < (1 << k)) 
				if (i > 0 && a[i - 1] < (1 << k))
					f[k].join(i - 1, i);
				if (i + 1 < n && a[i + 1] < (1 << k))
					f[k].join(i, i + 1);
			
			se.insert(f[k].goodLen.get());
		}
		a[i] -= sub;
	}
	
	reverse(all(ans));
	for (auto e: ans) 
		cout << e << '\n';
}

/*
	
*/

int32_t main() {

	if (fopen("input.inp", "r")) {
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	}
	
	ios::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);


	int tc; cin >> tc;
	while (tc--) {
        // DEBUG
		solve();
	}

	return 0;
}

/*
	nice bin string
	1 must go with 0
	0 must go with 1
 */
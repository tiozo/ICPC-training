#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
 
const int N = 1e5 + 9, Q = 3e5 + 9;
using ll = long long;
 
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

struct DSU { // DSU for each power of 2
  int n;
  int k;
  vector<int> par;
  vector<GoodSet> comp;
  maxSet goodLen;
  DSU() {}
  DSU(int n, int k): n(n), k(k) {
		par.resize(n + 1, -1);
		comp.resize(n + 1, GoodSet(k));
		for (int i = 0; i <= n; ++i) {
			goodLen.insert(comp[i].get());
		}
	}
  int find(int u) {
		return (par[u] == -1 ? u : par[u] = find(par[u]));
	}
//   void join(int u, int v) {
//     u = find(u); v = find(v);
//     if (u == v) return;
//     goodLen.erase(comp[u].get());
//     goodLen.erase(comp[v].get());
 
//     // small to large merging
//     if (comp[u].mp.size() < comp[v].mp.size()) {
//       comp[u].mp.swap(comp[v].mp);
//       swap(comp[u].size, comp[v].size);
//     }
//     comp[u].merge(comp[v]);
//     comp[v].mp.clear(); // clear to save up memory
 
//     goodLen.insert(comp[u].get());
//     par[v] = u;
//   }
  bool join(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		goodLen.erase(comp[u].get());
		goodLen.erase(comp[v].get());

		if (comp[u].mp.size() < comp[v].mp.size()) {
			comp[u].mp.swap(comp[v].mp);
			swap(comp[u].size, comp[v].size);
		}
		comp[u].merge(comp[v]);
		comp[v].mp.clear();

		goodLen.insert(comp[v].get());
		par[v] = u;
		return true;
	}
  // insert or erase an element from the component that u belongs to
  void update(int u, int x, bool insert = true) {
    u = find(u);
    goodLen.erase(comp[u].get());
    if (insert) comp[u].insert(x);
    else comp[u].erase(x);
    goodLen.insert(comp[u].get());
  }
};

DSU f[18];
ll a[N]; // make it long long as total sum can be huge
int id[Q], x[Q], ans[Q];
void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> id[i] >> x[i];
    a[id[i]] += x[i];
  }
  maxSet se;
  for (int k = 0; (1 << k) <= n; k++) {
    f[k] = DSU(n, k);
    for (int i = 1; i <= n; i++) {
      if (a[i] < (1 << k)) {
        f[k].update(i, a[i], true);
      }
    }
    for (int i = 2; i <= n; i++) {
      if (a[i] < (1 << k) and a[i - 1] < (1 << k)) {
        f[k].join(i - 1, i);
      }
    }
    se.insert(f[k].goodLen.get());
  }
  for (int qid = q; qid >= 1; qid--) {
    ans[qid] = se.get();
    int i = id[qid], sub = x[qid];
    for (int k = 0; (1 << k) <= n; k++) {
      se.erase(f[k].goodLen.get());
 
      if (a[i] < (1 << k)) f[k].update(i, a[i], false);
      if (a[i] - sub < (1 << k)) f[k].update(i, a[i] - sub, true);
 
      if (a[i] >= (1 << k) and a[i] - sub < (1 << k)) {
        if (i > 1 and a[i - 1] < (1 << k)) {
          f[k].join(i - 1, i);
        }
        if (i + 1 <= n and a[i + 1] < (1 << k)) {
          f[k].join(i, i + 1);
        }
      }
 
      se.insert(f[k].goodLen.get());
    }
    a[i] -= sub;
  }
 
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
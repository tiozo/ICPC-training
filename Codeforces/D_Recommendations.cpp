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

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}

ll lcm(ll x, ll y) {
    return (x * y) / gcd(x, y);
}

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

struct Line {
    int l, r, id; 
    Line(int l = 0, int r = 0): l(l), r(r) {};
    bool operator < (const Line& a) {
        return l != a.l ? l < a.l : -r < -a.r;
    }
};

void solve() {
    int n; see(n);
    vector<Line> a(n);
    int idx = 0;
    for (auto &[l, r, id]: a) 
        cin >> l >> r, id = idx++;
    map<pair<int, int>, int> cnt;
    for (auto [l, r, id]: a) {
        cnt[{l, r}]++;
    }
    vector<int> dup(n, 0);
    for (auto [l, r, id]: a) {
        if (cnt[{l, r}] >= 2) {
            dup[id] = 1;
        }
    }
    vector<int> ans(n, 0);
    for (int it = 0; it < 2; ++it) {
        for (auto &[l, r, id]: a) 
            l *= -1, r *= -1, swap(l, r);
        sort(all(a));
        set<int> s;
        for (auto &[l, r, id] : a) {
            if (!dup[id]) {
                auto iter = s.lower_bound(r);
                if (iter != s.end()) {
                    ans[id] += *iter - r;
                } 
            }
            s.insert(r);
        }
    }
    for (int e: ans) cout << e << '\n';
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
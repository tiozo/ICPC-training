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

void solve() {
	int n, m, q; see(n, m, q);
    vector<int> a(n), b(m);
    vector<bool> mpA(2 * n + 10, 0), mpB(2 * m + 10, 0);
    ll sumA = 0, sumB = 0;
    for (int &e: a) see(e), sumA += e, mpA[n + e] = 1;
    for (int &e: b) see(e), sumB += e, mpB[m + e] = 1;

    auto Test = [&](int x, int y) {
        auto need_a = sumA - x;
        auto need_b = sumB - y;
        if (abs(need_a) <= n && mpA[need_a + n]) {
            if (abs(need_b) <= m && mpB[need_b + m]) {
                return true;
            }
        }
        return false;
    };

    while (q--) {
        bool flag = false;
        int x; see(x);
        for (int d = 1;1ll * d * d <= abs(x); ++d) {
            if (x % d) continue;
            flag |= Test(d, x / d);
            flag |= Test(-d, -(x / d));
            flag |= Test(x / d, d);
            flag |= Test(-(x / d), -d);
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
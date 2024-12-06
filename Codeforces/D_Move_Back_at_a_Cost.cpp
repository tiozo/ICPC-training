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
	return (a.first != b.first ? a.first < b.first : a.second < b.second);
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
	int n; cin >> n;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    vector<int> stk, b;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && stk.back() > a[i]) {
            b.push_back(stk.back() + 1); stk.pop_back();
        }
        stk.push_back(a[i]);
    }
    sort(all(b));
    while (!b.empty() && stk.back() > b[0]) {
        b.push_back(stk.back() + 1); stk.pop_back();
    }
    sort(all(b));
    a = stk;
    for (auto e: b) 
        a.push_back(e);
    for (auto e: a) {
        cout << e << ' ';
    }
    cout << '\n';
}

/*
	1 9 9 3 2 5
    1 9 9 2 4 6
    1 2 4 6 10 10
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
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
	int n; cin >> n;
    vector<vector<int>> a(3, vector<int>(n + 1));
    for (auto &v: a) {
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
    }
    string s = "QKJ";
    vector<pair<char, int>> tmp(n + 1, {'\0', -1});
    int mins[3] = {n, n, n};
    for (int i = n - 1; i >= 1; --i) {
        // cerr << i << ' ' << mins[0] << ' ' << mins[1] << ' ' << mins[2] << '\n';
        int win = -1;
        for (int x = 0; x < 3; ++x) 
            if (a[x][i] > a[x][mins[x]]) win = x;
        if (win == -1) continue;
        // cout << win << '\n';
        tmp[i] = {s[win], mins[win]};
        for (int x = 0; x < 3; ++x) 
            if (a[x][i] < a[x][mins[x]]) mins[x] = i; 
    }

    if (tmp[1].second == -1) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";

    vector<pair<char, int>> ans = {tmp[1]};
    while (ans.back().second >= 0) {
        ans.push_back(tmp[ans.back().second]);
    }
    ans.pop_back();
    cout << sz(ans) << '\n';
    for (auto && [c, v]: ans) {
        cout << c << ' ' << v << '\n';
    }
}

/*
	p[1] -> 
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
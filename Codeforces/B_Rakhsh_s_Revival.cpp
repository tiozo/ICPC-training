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

void solve() {
	int n, m, k; cin >> n >> m >> k; 
    string s; cin >> s;
    int cnt = 0;
    vector<int> sec;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++cnt;
        } else {
            sec.push_back(cnt);
            cnt = 0;
        }
    }
    sec.push_back(cnt);
    ll res = 0;
    for (int e: sec) {
        // cout << e << ' ';
        if (e >= m) {
            if (e == k) {
                ++res; continue;
            }
            int x = e - m;
            res += floor(1.0 * (x) / k);
            // cout << x << '\n';
        }
    }
    cout << res << '\n';
}

/*
	max n / k
    6 3 2
    1
    6 3 1
    001100 = 2

    6 3 2
    001100 = 3 - 2 = 1

    6 3 3 
    000111 = 
    6 / 3

    7 3 2
    0000000
    7 / 3 = 2.3

    maximum segment = sec[i] / m 

    e % k == 0 ->
    6 % 2 3
    6 % 3 3
    6 % 1 3

    002
    002
    220

    0000 
    0000 
    000
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
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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return (a.second != b.second ? a.second < b.second : a.first < b.first);
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

int fen[N];
void update(int x, int val) {
    for (int p = x; p < N; p += p & -p) {
        ckmin(fen[p], val);
    }
}

int get(int x) {
    int res = N;
    for (int p = x; p > 0; p -= p & -p) {
        ckmin(res, fen[p]);
    }
    return res;
}

void solve() {
	int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    vector<int> b(m);
    for (int &e: b) cin >> e;

    memset(fen, inf, sizeof fen);
    int idx = 1;
    for (int &e: a) {
        update(e, idx++);
    }
    for (int e: b) {
        int f = get(e);
        if (f < N) {
            cout << f << '\n';
        } else 
            cout << "-1\n";
    }
}

/*
	60 83 76 45 70 91 37 58 94 22
    0  0  0  3  3  3   6 6  6  6

       2 
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
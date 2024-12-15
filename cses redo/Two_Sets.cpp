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
	int n; see(n);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) sum += i;
    if (sum % 2) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    vector<int> a, b;
    vector<int> vis(n + 1, 0);
    ll firstHalf = sum / 2;
    for (int i = n; i >= 1; --i) {
        if (firstHalf - i < 0) continue;
        vis[i] = true;
        a.push_back(i);
        firstHalf -= i;
    }
    for (int i = n - 1; i >= 1; --i) {
        if (vis[i] == 0) 
            b.push_back(i);
    }
    cout << sz(a) << '\n';
    for (int e: a) cout << e << ' ';
    cout << '\n';
    cout << sz(b) << '\n';
    for (int e: b) cout << e << ' ';
    cout << '\n';
}

/*
	8 
    1 2 3 4 8 
    5 6 7 
    3 -> YES
    4 -> NO
    5 -> YES
    1 5 2 
    4 3 
    7 6 1
    2 3 4 5
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
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
	int a[3], n;
    see(n, a[0], a[1], a[2]);
    int cnt = 0;
    int maxDay = a[0] + a[1] + a[2];
    int lt = n % maxDay;
    int Days = floor(1.0 * n / maxDay) * 3;
    if (0 < lt && lt <= a[0]) cnt = 1;
    if (a[0] < lt && a[0] + a[1] >= lt) cnt = 2;
    if (a[0] + a[1] < lt && a[0] + a[1] + a[2] >= lt) cnt = 3;
    cout << Days + cnt << '\n';
}

/*
	x * a + y * b + z * c >= n
    12 / 1 = 12
    12 / 5 = 2
    12 / 3 = 4
    a b c
    11 % 5 = 1
    12 - 1 = 11
    11 - 5 = 6
    6 - 3 = 3
    3 - 1 = 2
    2 - 5 = 0
    12 / 9 = 1
    3 / 6 = 0
    16 3 4 1 
    16 / 8 = 2
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
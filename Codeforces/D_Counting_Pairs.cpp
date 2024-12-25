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
	int n; ll x, y; cin >> n >> x >> y;
    vector<int> a(n);
    ll sum = 0;
    for (int &e: a) 
        cin >> e, sum += e;
    sort(all(a));
    ll res = 0;
    ll sumx = sum - x, sumy = sum - y;
	int l = n, r = n;
	for (int i = 0; i < n; ++i) {
		while (l > 0 && a[i] + a[l - 1] >= sumy) --l;
		while (r > 0 && a[i] + a[r - 1] > sumx) --r;
		res += max(r, i + 1) - max(l, i + 1);
		// cout << l << ' ' << r << '\n';
	}

    cout << res << '\n';
}

/*
    duyet tu phai qua trai
	    chon phan tu hien tai lam moc. 
        dem xem co bao nhieu so <= sum - e 
        res += sum - e;

    3 4 4 5 6 9
            
    sum - (a[i]) - y <= a[j];
    x <= sum - a[i] - a[j]

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
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
	int n, m; see(n);
    ll sa = 0, sb = 0;
    vector<int> a(n);
    for (int &e: a) see(e), sa += e;
    see(m);
    vector<int> b(m);
    for (int &e: b) see(e), sb += e;
    
    if (sa != sb) {
        cout << "-1\n"; return;
    }
    int cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        // cerr << i << ' ' << j << '\n';
        if (a[i] == b[j]) {
            ++i, ++j; ++cnt; continue;
        }
        ll sumA = a[i], sumB = b[j];
        int ii = i + 1, jj = j + 1;
        while (sumA != sumB) {
            // cerr << ii << ' ' << jj << ' ' << sumA << ' ' << sumB << '\n';
            while (ii < n && sumA < sumB) sumA += a[ii], ++ii;
            while (jj < m && sumA > sumB) sumB += b[jj], ++jj;
        }
        // cerr << sumA << ' ' << sumB << '\n';
        i = ii, j = jj; ++cnt;
    }
    cout << cnt << '\n';
}

/*
	statement summary:
    perform operations: 
        + take some consecutive subsegment
            replace with a single elements x
        + x = sum of elements in the subsegment.
    array A = B if and only: 
        + len(a) = len(b)
        + a[i] = b[i] (1 <= i <= len(a) = len(b))
    operations can be perform on A or B
    make A = B with 'max(length)'

    |      |
    11 10 7
    11 10 7
    max = 3
    ans = -1 only when sum(A) != sum(B)

    if sum(A) = sum(B) 
        + smaller result = 1
    
    sum = 40
    21 5 9 3 23
    20 20

    |
    a[i]   
    b[i] 
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
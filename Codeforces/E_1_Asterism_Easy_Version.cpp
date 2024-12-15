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
	int n, p; cin >> n >> p;
    vector<int> a(n);
    for (int &e: a) cin >> e;
    sort(all(a));
    int mx = -inf;
    /// account for the maximal of candies needed to win.
    for (int i = 0; i < n; ++i) {
        ckmax(mx, a[i] - i);
    }
    // cout << mx << '\n'; 
    int k = 0;
    for (int i = 0; i < n; ++i) {
        // cout << mx - a[i] + i << ' ';
        if (i >= p - 1) {
            /// let say that, this round resulted in a win.
            /// the minimal value of candies is mx - a[i] + i.
            /// a[i] + i is amount of candies at positions i-th. 
            /// (say that all the previous round was a win).
            /// if, the current x (mx) isn't enough to win everyround. 
            /// then that round need at least ith candies.
            ckmax(k, min(mx - (a[i] - i), i));
        }
    }
    k = max(p - k - 1, 0);
    cout << k << '\n';
    for (int i = 0; i < k; ++i) {
        cout << mx + i << ' ';
    }
}

/*
    Statement Summaries.
	Yuzu has x candies
    n enemies (1 -> n)
    each enemy has a[i] candies
    Yuzu deter permutations of her sets of candies.
    Duels rules: 
        + yuzu has equal or more candies then enemy p[i] 
            -> wins ans +1 candies
        + the new candy can be use in next duels. 
    
    find how many permutations to make Yuzu win all duels

    Define a f(x) as number of permutations for x

    given n, a and prime number p <= n. Call a possitive 
    integer 'x' good if f(x) is not divisible by p. 
    Find all 'x'.
    
    ideas: 
    X requiremens: 
        + x >= min(a[i]);
        + f(x) % p != 0
        after each wins she will gradually gain more candies. 
        + at maximal x can be infinite (?) 
            -> NO, x must be <= max(a[i]) if x grow more,
            then it is pointless. 
    3 4 5
    x = 3
    123 
    x = 4
    123
    132
    213
    231
    x = 5
    

    
    2 3 5 6
    ckmax(k, min(mx - (a[i] - i), i));
    k = 0
    mx = 3
    0 1 2 3
    2 3 5 6
    3 - 2 + 0 = 1, 0 -> can't use the first value since it resulted in missing 1 value
    3 - 3 + 1 = 1, 1 -> same
    3 - 5 + 2 = 0, 2 -> yes 
    3 - 6 + 3 = 0, 3 -> yes
    so we can use pos 3 and pos 4 to win this match.
    the amount of divisible by a number is 0 -> p - 1
    so the maximal f(x) is < p

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
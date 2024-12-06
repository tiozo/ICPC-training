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
	int n, m, v; cin >> n >> m >> v;
    vector<int> a(n);
    for (int &e: a) cin >> e;

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    
    /// the maximal amount is m
    vector<int> L(m + 1, 0);
    vector<int> R(m + 1, 0);

    for (int i = 1, j = 0; i <= m; ++i) {
        while (j <= n && prefix[j] - prefix[L[i - 1]] < v) {
            ++j;
        }
        L[i] = j;
    }
    R[0] = n;
    for (int i = 1, j = n; i <= m; ++i) {
        while (j >= 0 && prefix[R[i - 1]] - prefix[j] < v) {
            --j;
        }
        R[i] = j; 
    }

    ll ans = -1;
    for (int i = 0; i <= m; ++i) {
        if (R[m - i] >= L[i])
            ckmax(ans, prefix[R[m - i]] - prefix[L[i]]);
        // cout << "MARK: " <<  L[i] << ' ' << R[m - i] << '\n';
    }
    cout << ans << '\n';
}

/*
	n sections with a[i] tastiness
    1 <= a[i] <= 10^9
    Alice want to divide N into
        + m pieces with the minimum amount is V
    and
        + call ANS = 1 pieces have maximal tastiness (could be 0)

    M pieces first then the maximal left. That why it have a 0
    if can, print out ans. 
    if can't divide then print -1. 

    Ideas: 
        Theres always be an interval containing 
        the portions for Alice. If M part is divided. 
        So we just need to know the ending of those portions
        and take it out. 

        The portion for Alice is continuous, so there is no case
        where 
            + Alice can have a portion out side with 
                x <unowned portion> x <alice portions> 
        

    greedy way:
    pick the smallest amount of cake to feed the monster
    m ways from the Left -> Right
    m ways from the Right -> Left

    question, we have all the possible way to feed the monster
    from the both side. 

    Let's say L[i], R[i] is the portions for the i-th monster
    from Left to Right and Right to Left respectively.

    then the portions for Alice is 
    just the MAX of L[i] to R[m - i]
    take i's portions from the left, and (m - i)'s portions from the right.
    the Left over is the Alice portions. 
    a valid portions is where L[i] <= R[m - i]
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
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
	int n, k; cin >> n >> k;
	vector<vector<ll>> dp(k + 1, vector<ll> (n + 1));
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = 1;
	}
	for (int l = 1; l <= k - 1; ++l) {
		for (int x = 1; x <= n; ++x) {
			for (int i = 1; i * x <= n; ++i) {
				add(dp[l + 1][i * x], dp[l][x]);
			}
		}
	}
	ll ans = 0;
	for (int x = 1; x <= n; ++x) {
		add(ans, dp[k][x]);
	}
	cout << ans << '\n';
}

/*
	n, k <= 2000
	pick K integers from a sequence from 1 -> n
	so that all the integers in the sequence
	a[i] % a[i + 1] == 0
	a[i] <= n
	O(n * k * log n) = MAXIMUM LIMIT
	generate all the divisor of N
	a[i] -> divisor of a[i] 
	divisors of a[i] is pick 1 from set
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
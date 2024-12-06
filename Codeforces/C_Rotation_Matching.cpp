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

struct Data_ {
    int val, lDis, rDis;

};

int find_position(const vector<pair<int, int>>& a, int x) {
    int l = 0;
    int r = (int)a.size() - 1;   // [l, r] is our search space
    while (l <= r) {             // search space is non-empty
        int m = l + (r - l) / 2; // "middle" position in the range
        if (a[m].first == x) return a[m].second; // found!
        else if (a[m].first < x) {
            l = m + 1;           // remove all indices <= m from the search space
        } else {
            r = m - 1;           // remove all indices >= m from the search space
        }
    }
    return a.size();                    // failure
}

void solve() {
	int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &e: a) cin >> e;
    for (int &e: b) cin >> e;
    
    unordered_map<int, int> cnt;
    /// first - value, second - orginal index.
    vector<pair<int, int>> arr;
    
    /// recompressing into correct order.
    for (int i = 0; i < n; ++i) {
            arr.push_back({b[i], i});
    }
    
    auto cmp = [&](pair<int,  int> a, pair<int, int> b) {
        return (a.first != b.first ? a.first < b.first : a.second < b.second);
    };
    sort(all(arr), cmp);

    /// building dif array.
    for (int i = 0; i < n; ++i) {
        //cout << i << '\n';
        int e = a[i];
        int idx = find_position(arr, e);
        int dif; 
        if (i - idx >= 0) 
            dif = i - idx;
        else 
            dif = n + i - idx;
        ++cnt[dif];
    }

    int goodTurn = 0, cur_val = 0;
    //cnt[k] = e
    for (auto [k, e]: cnt) {
        if (cur_val < e) {
            goodTurn = k;
            cur_val = e;
        }
    } 

    int res = cnt[goodTurn];
    

    cout << res << '\n';
}

/*
    seq a and b
	+ i = j && a[i] = b[j]
    + choose k -> shift K-th times 
    Other way of saying 
    Shift i -> i + k and cycle. 

    idea 1: 
        + Deque O(n) shift time N is at worst n.
        shift -> then -> O(n^2)
        Pre-calculating the furthest distance
        -> O(K * N); atmost time won't surpass the limit
    idea 2: 
        + Finding the most occurance distance in 
        the array.
        -> Need to find the distances in 2 ways.
    dist = i - j, n - (i - j)
    i = 3
    j = 1
    dist_l = 3 - 1
    dist_r = n - dist_l = 5 - 2 = 3
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
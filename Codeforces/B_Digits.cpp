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
	int n, d; see(n, d);

    set<int> ans;
    ans.insert(1);
    if (d == 3) {
        ans.insert(3);
    } else if (d == 5) {
        ans.insert(5);
    } else if (d == 6) {
        ans.insert(3);
    } else if (d == 7) {
        ans.insert(7);
    } else if (d == 9) {
        ans.insert(3);
        ans.insert(9);
    }
    if (n >= 3 && n < 6) {
        if (d == 3 || d == 6 || d == 9)
            ans.insert(3),
            ans.insert(7),
            ans.insert(9);
        else 
            ans.insert(3);
            ans.insert(7);
    } else if (n >= 6) {
        ans.insert(3);
        ans.insert(7);
        ans.insert(9);
    }
    std::vector<int> ansList(ans.begin(), ans.end());
    std::sort(ansList.begin(), ansList.end());

    for (int e: ans) put(e);
    
    cout << '\n';
}

/*
	6 2!
    66
    1 
    2 when d % 2 == 0
    3 when d = 3 d = 6 d = 9
    4 when d = 4, d = 8
    5 when d = 5 
    6 when vis[2] = true and vis[3] = true
    7 when d = 7 d = 5 if n >= 5
    8 when ddd % 8 = 0
    9 when d = 9 
    d = 4 n = 4
    55555
    1 2 6 24 120
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
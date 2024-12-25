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
	int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int &e: a) cin >> e;

    vector<int> ans;
    stack<int> s;
    s.push(N), s.push(n + 1);
    int curValue = 1;
    for (int i = 0; i < n; ++i) {
        if (i >= k)
            a.push_back(s.top() - 1);
        s.push(a[i]);
        while (!s.empty() && s.top() == curValue) {
            ++curValue;
            s.pop();
        }
    }
    if (sz(s) > 1) {
        cout << "-1\n";
    } else {
        for (int e: a) {
            cout << e << ' ';
        }
    }
}

/*
	3 4 1 2 5 6

    a
    3 4 1 2 5 6
    s
    3 4 
    b
    1 2
    
    5 2
    4 2 
    4 2 1 3 5
    1 2 3 4 5

    4 3 2 1 6 5 

    6 4 2 1 3 5
    6 4 3 1 2 5
    2 1 3 4 
    1 

    3 2 6 4 1 5
    3 2 6

    6 3 4 1 2 5

    x and y
    -> abs(x - y) = 1 

    O(n log^2 n )
    O(n log n sqrt n)
*/

int32_t main() {

	if (fopen("input.inp", "r")) {
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	}
	
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
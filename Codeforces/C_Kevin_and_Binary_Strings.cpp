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

ll point(string s1, string s2) {
    ll res = 0;
    ll points = 1;
    // cout << s1 << ' ';
    int i = sz(s1) - 1, j = sz(s2) - 1;
    while (i >= 0 && j >= 0) {
        if (s1[i] != s2[j]) {
            s1[i] = '1';
        } else {
            s1[i] = '0';
        }
        --i, --j;
    }
    // cout << s1 << '\n';
    for (int i = sz(s1) - 1; i >= 0; --i) {
        if (s1[i] == '1')
            res += points * 2; ++points;
    }
    return res;
}

void solve() {
	string s; cin >> s;
    /// pos of first 0
    int pos = 0;
    for (auto c: s) {
        if (c == '0') break;
        ++pos;
    }
    // cout << pos << '\n';
    int n = sz(s);
    int mxLen = sz(s) - pos;
    if (mxLen == 0) {
        cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << n << '\n'; return;
    }
    int best = -1;
    vector<int> cur;
    for(int st = 0; st + mxLen <= n; st++){
        vector<int> x;
        for(char c : s) x.push_back(c - '0');
        for(int i = 0; i < mxLen; i++){
            if(s[st+i] == '1') x[n - mxLen + i] ^= 1;
        }
        if(x > cur){
            cur = x;
            best = st;
        }
    }
    cout << 1 << ' ' << n << ' ' << (best + 1) << ' ' << (best + mxLen) << '\n';
}

/*
	11101
    10
    11000001000
      1 

    1101
    4301

    10
    01
    21    
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
        // DEBUG
		solve();
	}

	return 0;
}

/*
	nice bin string
	1 must go with 0
	0 must go with 1
 */
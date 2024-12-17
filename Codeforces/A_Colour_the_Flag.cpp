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

vector<pair<int, int>> moveset = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void solve() {
	int n, m; cin >> n >> m;
    vector<string> a(n);
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    bool allDots = true;
    queue<pair<int, int>> q;
    int row = 0;
    for (auto &e: a) {
        see(e);
        for (int i = 0; i < m; ++i) {
            if (e[i] != '.') {
                q.push({row, i});
            }
        }
        ++row;
    }

    if (sz(q) == 0) {
        a[0][0] = 'R';
        q.push({0, 0});
    }

    auto inbound = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    bool flag = false;

    // cerr << sz(q) << ' ' << row << '\n';
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        // cerr << x << ' ' << y << '\n';
        for (auto e: moveset) {
            int xx = x + e.first;
            int yy = y + e.second;
            // assert(inbound(x, y));
            if (inbound(xx, yy)) {
                // cerr << x ;
                if (a[x][y] == 'R' && (a[xx][yy] == 'W' || a[xx][yy] == '.')) {
                    a[xx][yy] = 'W';
                } else 
                if (a[x][y] == 'W' && (a[xx][yy] == 'R' || a[xx][yy] == '.')) {
                    a[xx][yy] = 'R';
                } else {
                    flag = true;
                }
                q.push({xx, yy});
            }
        }
        if (flag) break;
    }

    if (flag) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    for (auto e: a) {
        cout << e << '\n';
    }
}

/*
	
*/

int32_t main() {

	if (fopen("input.inp", "r")) {
		freopen("input.inp", "r", stdin);
		freopen("output.out", "w", stdout);
	}
	
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
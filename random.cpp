#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to count the number of 1s and 0s at a specific bit position in the list of numbers
pair<ll, ll> count_bits(const vector<ll>& nums, int bit_pos) {
    ll count_ones = 0;
    for (ll num : nums) {
        if ((num >> bit_pos) & 1) {
            count_ones++;
        }
    }
    ll count_zeros = nums.size() - count_ones;
    return {count_ones, count_zeros};
}

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (ll &e : a) cin >> e;

    ll xorProd = 1;
    const ll mod = 1e9 + 7;

    for (int bit_pos = 0; bit_pos < 64; ++bit_pos) {
        auto [count_ones, count_zeros] = count_bits(a, bit_pos);
        ll pairs_with_bit_set = count_ones * count_zeros;

        if (pairs_with_bit_set > 0) {
            xorProd = xorProd * binpow(1LL << bit_pos, pairs_with_bit_set, mod) % mod;
        }
    }

    if (l <= xorProd && xorProd <= r) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}

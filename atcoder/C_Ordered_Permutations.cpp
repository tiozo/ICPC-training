#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> getPrimes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

bool isPrime(int x, const vector<int>& primes) {
    for (int prime : primes) {
        if (x == prime) return true;
        if (prime > x) return false;
    }
    return false;
}

bool assignValues(int node, vector<int>& result, vector<bool>& used, const vector<vector<int>>& tree, const vector<int>& primes, int limit) {
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : tree[current]) {
            if (result[neighbor] == -1) {
                bool found_valid = false;
                for (int prime : primes) {
                    int offset = 0;
                    while (true) {
                        int num_add = result[current] + prime + offset;
                        if (num_add <= limit && !used[num_add] && !isPrime(abs(result[current] - num_add), primes)) {
                            result[neighbor] = num_add;
                            used[num_add] = true;
                            q.push(neighbor);
                            found_valid = true;
                            break;
                        }
                        int num_sub = result[current] - prime - offset;
                        if (num_sub > 0 && !used[num_sub] && !isPrime(abs(result[current] - num_sub), primes)) {
                            result[neighbor] = num_sub;
                            used[num_sub] = true;
                            q.push(neighbor);
                            found_valid = true;
                            break;
                        }
                        offset++;
                        if (num_add > limit && num_sub <= 0) break;
                    }
                    if (found_valid) break;
                }
                if (!found_valid) {
                    // Backtracking: attempt to assign values from 1 to 2*n
                    for (int num = 1; num <= limit; ++num) {
                        if (!used[num] && !isPrime(abs(result[current] - num), primes)) {
                            result[neighbor] = num;
                            used[num] = true;
                            q.push(neighbor);
                            found_valid = true;
                            break;
                        }
                    }
                    if (!found_valid) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void solve() {
    int t;
    cin >> t;

    vector<int> primes = getPrimes(400000);

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> result(n + 1, -1);
        vector<bool> used(2 * n + 1, false);

        result[1] = 1;
        used[1] = true;

        if (assignValues(1, result, used, tree, primes, 2 * n)) {
            for (int i = 1; i <= n; ++i) {
                cout << result[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    Fraction(int n, int d) : numerator(n), denominator(d) {}

    bool operator<(const Fraction& other) const {
        long long lhs = static_cast<long long>(numerator) * other.denominator;
        long long rhs = static_cast<long long>(other.numerator) * denominator;
        
        if (lhs == rhs) {
            return numerator < other.numerator; // Tie-breaking rule
        }
        return lhs < rhs;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Fraction> fractions;
    fractions.reserve(N);

    for (int i = 0; i < N; ++i) {
        int numerator, denominator;
        cin >> numerator;
        fractions.emplace_back(numerator, 0);
    }

    for (int i = 0; i < N; ++i) {
        cin >> fractions[i].denominator;
    }

    sort(fractions.begin(), fractions.end());

    for (const auto& fraction : fractions) {
        cout << fraction.numerator << " ";
    }
    cout << endl;

    for (const auto& fraction : fractions) {
        cout << fraction.denominator << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

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
    int N;
    cin >> N;

    vector<int> numerators(N);
    vector<int> denominators(N);
    vector<Fraction> fractions;

    // Read numerators
    for (int i = 0; i < N; ++i) {
        cin >> numerators[i];
    }

    // Read denominators
    for (int i = 0; i < N; ++i) {
        cin >> denominators[i];
    }

    // Combine numerators and denominators into fractions
    for (int i = 0; i < N; ++i) {
        if (denominators[i] != 0) { // Avoid dividing by zero
            fractions.push_back({numerators[i], denominators[i]});
        }
    }

    // Sort fractions
    sort(fractions.begin(), fractions.end());

    // Print sorted numerators
    for (const auto& fraction : fractions) {
        cout << fraction.numerator << " ";
    }
    cout << endl;

    // Print sorted denominators
    for (const auto& fraction : fractions) {
        cout << fraction.denominator << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute (a^b) % MOD using modular exponentiation
long long mod_exponentiation(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod; // in case a >= mod
    while (b > 0) {
        if (b % 2 == 1) // if b is odd, multiply a with the result
            result = (result * a) % mod;
        b = b >> 1;     // b = b / 2
        a = (a * a) % mod; // change a to a^2
    }
    return result;
}

int main() {
    int n;
    cin >> n; // number of test cases
    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << mod_exponentiation(a, b, MOD) << endl;
    }
    return 0;
}

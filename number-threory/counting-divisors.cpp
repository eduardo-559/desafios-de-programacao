#include <iostream>
#include <cmath>
using namespace std;

// Function to count the divisors of a number
int count_divisors(int x) {
    int count = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            count++; // i is a divisor
            if (i != x / i) {
                count++; // x / i is also a divisor, if it's different from i
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n; // number of integers
    while (n--) {
        int x;
        cin >> x;
        cout << count_divisors(x) << endl;
    }
    return 0;
}

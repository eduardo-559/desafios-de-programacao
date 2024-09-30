#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isDivisible(const vector<int>& numbers, int K) {
    unordered_set<int> currentMods, nextMods;
    currentMods.insert(0); // Iniciando com resto 0, considerando que qualquer número é divisível por si mesmo

    for (int num : numbers) {
        nextMods.clear();
        for (int mod : currentMods) {
            int modPlus = (mod + num) % K;
            if (modPlus < 0) modPlus += K;
            int modMinus = (mod - num) % K;
            if (modMinus < 0) modMinus += K;
            nextMods.insert(modPlus);
            nextMods.insert(modMinus);
        }
        currentMods.swap(nextMods);
    }

    return currentMods.find(0) != currentMods.end();
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int N, K;
        cin >> N >> K;
        vector<int> numbers(N);
        for (int i = 0; i < N; ++i) {
            cin >> numbers[i];
        }

        if (isDivisible(numbers, K)) {
            cout << "Divisible" << endl;
        } else {
            cout << "Not divisible" << endl;
        }
    }
    return 0;
}

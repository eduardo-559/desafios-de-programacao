#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// Função para gerar Gray code para n bits
vector<string> gray_code(int n) {
    vector<string> result;
    for (int i = 0; i < (1 << n); i++) {  // Loop de 0 até 2^n - 1
        int gray = i ^ (i >> 1);  // Gera o Gray code para o número i
        // Converte para uma string binária de n bits com zeros à esquerda
        result.push_back(bitset<16>(gray).to_string().substr(16 - n));
    }
    return result;
}

int main() {
    int n;
    cin >> n;  // Lê o valor de n

    // Gera o Gray code
    vector<string> gray_codes = gray_code(n);

    // Imprime o Gray code
    for (const string& code : gray_codes) {
        cout << code << endl;
    }

    return 0;
}

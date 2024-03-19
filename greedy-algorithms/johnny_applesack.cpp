#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    
    int km = 0;
    
    while(n > k) {
        km++;
        n = n - ceil((double) n/k);
    }
    
    km += n+1;
    cout << km;
}
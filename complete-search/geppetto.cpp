#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int a, b;
    cin >> n >> m;
    unordered_set<int> s;
    for(int i = 0; i < m;i++){
        cin >> a >> b;
        s.insert((1 << (a - 1)) | (1 << (b - 1)));
    }
    
    int range = (1 << n);
    int cont = 0;
    
    for(int i = 0; i < range;i++){
        bool validation = true;
        for(auto iteration : s){
            if((i & iteration) == iteration){
                validation = false;
                break;
            }
        }
        if(validation) cont++;
    }
    cout << cont;

    return 0;
}
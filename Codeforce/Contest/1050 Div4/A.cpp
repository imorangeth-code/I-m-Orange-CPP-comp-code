#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int a,b,sum=0;
        cin >> a >> b;
        if(b%2 == 0) cout << 0;
        else cout << a;
        cout << '\n';
    }
}
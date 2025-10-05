#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int count = 0;
        vector<bool> h(n+1,0);
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if(temp == k) count++;
            else if(h[temp] == 0) h[temp] = 1;
            else{
                count ++;
            }
        }
        cout << count << '\n';
       

    }
    return 0;
}

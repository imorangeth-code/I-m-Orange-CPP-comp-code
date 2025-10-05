#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i =0; i < n; i++) cin>> h[i];
        vector<int> temp(k,0);
        int count = 0;
        for(auto i : h){
            if(i == k) count ++;
            if(i < k)
                temp[i] = 1;
        }
        int m = 0;
        for(int i = 0; i < k; i++)
            if(temp[i] == 0)
            {
            m++;
            }
        cout << max(m,count) << '\n';
    }
    return 0;
}
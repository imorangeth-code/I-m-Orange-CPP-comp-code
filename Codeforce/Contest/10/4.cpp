#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a.push_back(i);
            else b.push_back(i);
        }
        
        if (a.empty() || b.empty()) {
            cout << 0 << "\n";
            continue;
        }
        
        long long r = 1e18;
        int ka = a.size(), kb = b.size();
        
        for (int t = 0; t < 2; t++) {
            vector<int>& v = (t == 0) ? a : b;
            int k = v.size();
            
            if (k == 0) continue;
            
            int m = k / 2;
            int st = v[m] - m;
            st = max(0, st);
            st = min(st, n - k);
            
            for (int of = -2; of <= 2; of++) {
                int i = st + of;
                if (i < 0 || i > n - k) continue;
                
                long long cost = 0;
                for (int j = 0; j < k; j++) {
                    cost += abs(v[j] - (i + j));
                }
                r = min(r, cost);
            }
        }
        
        cout << r << "\n";
    }
    return 0;
}
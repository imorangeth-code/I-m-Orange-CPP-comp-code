#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        sort(h.begin(), h.end());

        long long ans = 0;
        for (int i = 0; i < n; i+=2) {
            ans = max(ans, abs(h[i] - h[i+1]));
        }

        cout << ans << "\n";
    }

    return 0;
}

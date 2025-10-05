#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 1; 
        dp[0][1] = 1; 

        for (int i = 1; i < n; ++i) {
            int a0 = a[i - 1];
            int b0 = b[i - 1];
            int a1 = b[i - 1];
            int b1 = a[i - 1];
            int ca0 = a[i];
            int cb0 = b[i];
            int ca1 = b[i];
            int cb1 = a[i];
            if (a0 <= ca0) {
                if (b0 <= cb0) {
                    dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
                }
            }

            if (a0 <= ca1) {
                if (b0 <= cb1) {
                    dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
                }
            }

            if (a1 <= ca0) {
                if (b1 <= cb0) {
                    dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
                }
            }

            if (a1 <= ca1) {
                if (b1 <= cb1) {
                    dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
                }
            }
        }

        int ans = dp[n - 1][0] + dp[n - 1][1];
        if (ans >= MOD) {
            ans -= MOD;
        }
        cout << ans << endl;
    }

    return 0;
}

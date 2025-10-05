#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1'000'000'007;

int64 modpow(int64 a, int64 e) {
    int64 r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n_str;
    int m, k;
    if (!(cin >> n_str >> m >> k)) return 0;

    vector<string> a_str(m);
    for (int i = 0; i < m; ++i) cin >> a_str[i];

    int MAXN = m; 
    vector<int64> fact(MAXN + 1, 1), invfact(MAXN + 1, 1);
    for (int i = 1; i <= MAXN; ++i) fact[i] = fact[i-1] * i % MOD;
    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; --i) invfact[i] = invfact[i+1] * (i+1) % MOD;
    auto C = [&](int n, int r)->int64 {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
    };

    int pow10mod7[6];
    pow10mod7[0] = 1 % 7;
    for (int i = 1; i < 6; ++i) pow10mod7[i] = (pow10mod7[i-1] * 10) % 7;

    int S6 = 0;
    for (int i = 0; i < 6; ++i) S6 = (S6 + pow10mod7[i]) % 7;

    long long n_mod6 = 0;
    for (char c : n_str) {
        n_mod6 = (n_mod6*10 + (c - '0')) % 6;
    }
    int rem = 0;
    int q_mod7 = 0;
    for (char c : n_str) {
        int digit = c - '0';
        int cur = rem * 10 + digit;
        int qdigit = cur / 6;
        rem = cur % 6;
        q_mod7 = ( (q_mod7 * 10) + qdigit ) % 7;
    }
    int n_mod = (int)n_mod6;
    int R_full = ( (S6 * q_mod7) % 7 );
    for (int i = 0; i < n_mod; ++i) R_full = (R_full + pow10mod7[i]) % 7;

    vector<int> cnt(7, 0);
    int total_wsum = 0;
    for (int i = 0; i < m; ++i) {
        long long a_mod6 = 0;
        for (char c : a_str[i]) a_mod6 = (a_mod6*10 + (c - '0')) % 6;
        int exp_mod6 = (int)((a_mod6 - 1 + 6) % 6);
        int w = pow10mod7[exp_mod6] % 7;
        cnt[w] += 1;
        total_wsum = (total_wsum + w) % 7;
    }

    int R_cur = (R_full - total_wsum) % 7;
    if (R_cur < 0) R_cur += 7;
    int need = (7 - R_cur) % 7; 

    vector< vector<int64> > dp(k+1, vector<int64>(7, 0));
    dp[0][0] = 1;

    for (int v = 0; v < 7; ++v) {
        int c = cnt[v];
        if (c == 0) continue;
        vector<int64> choose(c+1);
        for (int t = 0; t <= c; ++t) choose[t] = C(c, t);

        vector< vector<int64> > dp2(k+1, vector<int64>(7, 0));

        for (int s = 0; s <= k; ++s) {
            for (int rem0 = 0; rem0 < 7; ++rem0) {
                int64 curv = dp[s][rem0];
                if (!curv) continue;
                for (int t = 0; t <= c; ++t) {
                    int ns = s + t;
                    if (ns > k) break;
                    int nrem = (rem0 + (t * v) ) % 7;
                    dp2[ns][nrem] = (dp2[ns][nrem] + curv * choose[t]) % MOD;
                }
            }
        }
        dp.swap(dp2);
    }

    int64 ans = 0;
    for (int s = 0; s <= k; ++s) ans = (ans + dp[s][need]) % MOD;
    cout << ans << '\n';
    return 0;
}

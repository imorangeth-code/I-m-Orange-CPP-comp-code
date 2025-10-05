#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    double ans[n][m];
    double minn = 10000000.0 ,maxn = -10000000.0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ans[i][j];
            minn = min(minn,ans[i][j]);
            maxn = max(maxn,ans[i][j]);
        }

    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << 0+((ans[i][j] - minn) / (maxn - minn)) * (1-0) << " ";
        }
        cout << '\n';
    }
}

// scaled_value = out_min + ((value - in_min) / (in_max - in_min)) * (out_max - out_min);
#include <bits/stdc++.h>

using namespace std;
#define int long long



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int m,n;
        cin >> m >> n;
        int mx = -1000000000000;
        for(int i = 0;i < m; i++)
        {
            int temp;
            cin >> temp;
            mx = max(temp,mx);
            
        }
        while(n--)
        {
            char c;
            int l,r;
            cin >> c >> l >> r; 
            if(mx>= l && mx <= r)
            {
                if(c == '-')mx--;
                else mx++;
            }
            cout << mx << " ";
        }
        cout << '\n';

    }
}
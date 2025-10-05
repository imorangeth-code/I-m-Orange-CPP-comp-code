#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin >> n;
    if (n < 100000)
    {
        cout <<2*n << '\n';
        for(int i =0; i < n; i++)
        {
            cout << "0 1 ";
        }

    }else {
        cout << "100000" << '\n';

        for(int i =0; i < 99999; i++)
        {
            cout << "0 ";
        }
        cout << n;

    }
    
}
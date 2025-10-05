#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 4*n ;i++)
    {
        for(int j = 0; j < 4*n; j++)
        {
            if(i < n && j >= n) cout << "#";
            else if (i < 2*n && i >= n && j < 2*n)cout << "#";
            else if (i < 3*n && i >= 2*n) cout << "#";
            else if(i >= 3 * n && ((j >= n && j < 2*n) || (j >= 3*n))) cout << "#";
            else cout << " ";
        }
        cout << '\n';
    }
}
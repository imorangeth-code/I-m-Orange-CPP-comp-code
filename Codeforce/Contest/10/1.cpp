#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int count = 0;
        int f = 0;
        for(int i =0 ;i < n; i++)
        {
            int k;
            cin >> k;
            if(k == 0) count++;
            else if(k == -1)
            {
                f++;
            }
        }
        if(f%2) count +=2;
        cout << count << '\n'; 
    }
}
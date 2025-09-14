#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 2*i; j < s.size()*2-1 ;j++)
        {
            cout << " ";
        }
        for(int j = 0; j <= 2*i; j++)
        {
            cout << s[abs(i-j)] << " ";
        }
        cout << '\n';
    }
}
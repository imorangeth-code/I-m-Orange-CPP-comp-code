#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,c = 0;
    cin >> n >> m;
    vector<int> v1;
    while(n--)
    {
        int t;
        cin >> t;
        v1.push_back(t);
    }
    for(auto i : v1)
    {
        if(i >= v1[m-1] && i > 0)c++;
    }
    cout << c;
    return 0;
}
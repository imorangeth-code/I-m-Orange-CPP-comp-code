#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> n;
    while(t--)
    {
        int x;
        cin >> x;
        n.push_back(x);
    }
    cout << *max_element(n.begin(),n.end()) << '\n' << *min_element(n.begin(),n.end());
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    vector<string> v;

    while (getline(cin, s, ' ')) {
        v.push_back(s);
    }
    for(int g  = v.size()-1 ; g>= 0; g--)
    {
        cout << v[g] << " ";
    }
    return 0;
}
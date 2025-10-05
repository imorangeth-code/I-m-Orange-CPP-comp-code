
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin ,str);
    string s;

    stringstream ss(str);

    vector<string> v;

    while (getline(ss, s, ' ')) {
        v.push_back(s);
    }
    for(int g  = v.size() ; g>= 0; g--)
    {
        cout << v[g] << " ";
    }
    return 0;
}
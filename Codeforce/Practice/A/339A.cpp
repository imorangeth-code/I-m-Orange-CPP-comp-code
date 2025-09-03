#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> v1;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i]))v1.push_back(int(s[i]));
    }
    sort(v1.begin(), v1.end());
    char c = char(v1[0]);
    string q = "";
    q+=c;
    int u = 0;
    for(auto i : v1)
    {
        u++;
        if(u == 1)continue;
        else{
            q+="+";
            q+=char(i);
        }
    }
    cout << q;
}

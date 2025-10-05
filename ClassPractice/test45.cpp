#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,in;
    cin >> a >> b >> in;
    string st = to_string(a*b);
    if(in > st.size()) cout << '_';
    else cout << st[in-1];
}
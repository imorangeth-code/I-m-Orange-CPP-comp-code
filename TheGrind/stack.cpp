#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    stack<int> b1;
    while(n--){
        string s;
        cin >> s;
        if(s == "push")
        {
            int t;
            cin >> t;
            b1.push(t);
        }else{
            if(!b1.empty())
            {
                int x = b1.top();
                 b1.pop();
                cout << x << "\n";
            }else{
                cout << "null" << '\n';
            }
            
        }
    }
}
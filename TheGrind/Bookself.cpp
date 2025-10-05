#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l,n;
    cin >> l >> n;
    vector<string> s;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        sum += k;
        string temp;
        cin >> temp;
        for(int j = 0; j <k; j++)
        {
            s.push_back(temp);
        }
    }
    sort(s.begin(), s.end());
    sum += sum+1;
    for(int i = 0; i < sum; i++)
    {
        if(i%2) cout<<"-";
        else cout << "+";
    }
    cout << '\n';
    

    for(int i =0; i < l; i++)
    {
        int m = 0;
        for(int j =0; j < sum; j++)
        {
            if(j%2){
                int si = s[m].size();
                if(m%2){
                    if(si + i < l)
                    {
                        cout << ".";
                    }else
                    {
                        string y = s[m];
                        reverse(y.begin(), y.end());
                        cout << y[abs(l-i-si)];
                    } 

                }else{
                    if(si - i > 0)
                    {
                        cout << s[m][i];
                    }else cout << ".";
                }
                m++;
            }
            else cout << "|";
        }
        cout << '\n';
    }

    for(int i = 0; i < sum; i++)
    {
        if(i%2) cout<<"-";
        else cout << "+";
    }



}
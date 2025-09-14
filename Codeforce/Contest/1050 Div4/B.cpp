#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        int t,m,x,y;
        cin >> t >> m >> x >> y;
        int temp;
        int c1=0,c2=0;      
        for(int i = 0; i < t; i++)
        {
            cin >> temp;
           c1++; 
        }
        for(int i = 0; i < m; i++){
            cin >> temp;
            c2++;
        }
        cout << c1+c2 << endl;
    }
}
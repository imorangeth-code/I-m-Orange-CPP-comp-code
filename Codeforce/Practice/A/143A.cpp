#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,count=0;
    cin >> t;
    while(t--){
        int sum = 0,x;
        for(int i = 0; i < 3; i++){
            cin >> x;
            sum+=x;
        }
        if(sum >= 2)count++;
    }
    cout << count << '\n';
}
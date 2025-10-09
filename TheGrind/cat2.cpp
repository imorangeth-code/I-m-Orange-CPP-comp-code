#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
void testcase(){
    int n;
    cin >> n;
    char s[2][5001];
    cin >> s[0] >> s[1];
    int cnt=(s[0][0]=='.')+(s[1][0]=='.');
    for(int i=0; i<n-1; i++){
        if((s[0][i]=='#' || s[0][i+1]=='#') && (s[1][i]=='#' || s[1][i+1]=='#')) cnt=0;
        if(!(s[0][i]=='#' || s[1][i]=='#' || s[0][i+1]=='#' || s[1][i+1]=='#')) cnt=(cnt<<1)%MOD;
    }
    if(s[0][n-1]=='#' && s[1][n-1]=='#') cnt=0;
    if(!(s[0][n-1]=='#' || s[1][n-1]=='#')) cnt=(cnt<<1)%MOD;
    cout << cnt << '\n';
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
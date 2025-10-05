#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 43;
vector<bool> dp(MAX_N, 0); 

bool nugget(short n) {
	if(n < 6) return 0;
	if(dp[n]) return dp[n];
	if(n == 6 || n == 9 || n == 20) return dp[n] = 1;

	dp[n] = nugget(n - 6) || nugget(n - 9) || nugget(n - 20);
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    long long int count = 0;
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        
        if(l == r)
        {
            if(nugget(l))count++;
            continue;
        }
        if(l < 44 && r >= 44)
        {
            for(int i = l; i <= 44; i++) {
		    if(nugget(i)) count ++;
            }
            count += r-44;
	    }else if (l < 44 && r < 44)
        {
            for(int i = l; i <= r; i++) {
		    if(nugget(i)) count ++;
            }
        }else{
            count += r-l+1;
        }
    
	
    }
    cout << count;

	return 0;
}


// original code  https://programming.in.th/submissions/394267
// my teacher at nangrong kai 1

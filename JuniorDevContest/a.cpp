#include<bits/stdc++.h>
using namespace std;

bool isSut(long long n) {
    string s = to_string(n);
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        if ((s[i] - '0') + (s[j] - '0') != 10) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long l, r;
    cin >> l >> r;
    
    if (r - l <= 1000000) {
        int cnt = 0;
        for (long long i = l; i <= r; i++) {
            if (isSut(i)) cnt++;
        }
        cout << cnt;
        return 0;
    }
    
    int cnt = 0;
    
    queue<string> q;
    q.push("5");
    
    for (int d = 1; d <= 9; d++) {
        q.push(to_string(d) + to_string(10 - d));
    }
    
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        
        long long num = stoll(s);
        if (num > r) continue;
        if (num >= l) cnt++;
        
        // Generate next numbers by adding digit pairs
        if (s.length() % 2 == 0) { // Even length - can add middle 5
            string with_middle = s.substr(0, s.length() / 2) + "5" + s.substr(s.length() / 2);
            long long mid_num = stoll(with_middle);
            if (mid_num <= r) {
                if (mid_num >= l) cnt++;
                // Continue from this
                for (int d = 1; d <= 9; d++) {
                    string next = s.substr(0, s.length() / 2) + to_string(d) + to_string(10 - d) + s.substr(s.length() / 2);
                    if (next.length() <= 16) {
                        q.push(next);
                    }
                }
            }
        } else { // Odd length - add digit pairs around
            int mid_pos = s.length() / 2;
            for (int d = 1; d <= 9; d++) {
                string next = s.substr(0, mid_pos) + to_string(d) + to_string(10 - d) + s.substr(mid_pos + 1);
                if (next.length() <= 16) {
                    q.push(next);
                }
            }
        }
    }
    
    cout << cnt;
    return 0;
}
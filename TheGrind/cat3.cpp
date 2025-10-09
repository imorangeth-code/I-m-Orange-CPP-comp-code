#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    string key;
  string s;
  cin >> c >> key >> s;
  string ans = "";
  string temp = "";
  for(int i = 0; i < s.size(); i++)
  {
      if(c == 'd')
      {
          int y = key.size();
          int u = s[i]-'a';
          u += abs((key[i%y] - 'a') - 26);
          ans+=char(u%26+'a');
      }else{
          int u = s[i]-'a';
          int y = key.size();
          u+=(key[i%y] - 'a');
          ans+=char(u%26+'a');
      }
  }
  cout << ans << '\n';
}

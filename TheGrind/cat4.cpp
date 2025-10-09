#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  string ans = "";
  string temp = "";
  for(auto i : s)
  {
    if(i == ':'){
      if(temp.size()%2)
      {
        for(auto j : temp)
        {
          int y = temp.size();
          int u = j-'a';
          u = abs(y - 26);
          ans+=char(u%26+'a');
        }
      }else{
        for(auto j : temp)
        {
          int u = j-'a';
          u+=temp.size();
          ans+=char(u%26+'a');
        }
      }
      ans+=':';
      temp.clear();
    }
    else{
      temp+=i;
    }
  }
  if(!temp.empty())
  {
    if(temp.size()%2)
      {
        for(auto j : temp)
        {
          int y = temp.size();
          int u = j-'a';
          u = abs(y - 26);
          ans+=char(u%26+'a');
        }
      }else{
        for(auto j : temp)
        {
          int u = j-'a';
          u+=temp.size();
          ans+=char(u%26+'a');
        }
      }
  }

  cout << ans << '\n';
}

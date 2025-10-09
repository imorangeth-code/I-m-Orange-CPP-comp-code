#include <bits/stdc++.h>

using namespace std;

struct Match{
    string name;
    int a[4];
    int s1;
    int s2;
    int s3;
};

bool compareScore(Match a, Match b)
{
    if(a.s1 != b.s1) return a.s1 > b.s1;
    if(a.s2 != b.s2) return a.s2 > b.s2;
    return (a.s3 > b.s3);
}

void computeRanks(Match s[], int n)
{
    for(int i =0; i < n; i++) {
        s[i].s1 = 0, s[i].s2 = 0, s[i].s3=0;
        for(int j =0; j < n; j++)
        {
            if(i!=j){
                if(s[i].a[j] > s[j].a[i]) s[i].s1+=3;
                else if(s[i].a[j]==s[j].a[i]) s[i].s1+=1;
                s[i].s2 += s[i].a[j]-s[j].a[i];
                s[i].s3 += s[i].a[j];
            }
        }
    }
    sort(s,s+4,compareScore);
}

int main()
{
    int n = 4;
    Match s[n];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i].name;
    }
    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            cin >> s[i].a[j];
        }
    }
    computeRanks(s,n);
    for(int i =0; i < n; i++)
    {
        cout << s[i].name << " " << s[i].s1 << '\n';
    }
    return 0;
}
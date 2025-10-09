#include<bits/stdc++.h>
using namespace std;
long long int l,r,cnt=0;
void think(string f,string b){
	//cout<<f<<" "<<b<<"\n";
	long long int y=stoll(f+b),yy=stoll(f+"5"+b);
	if(y>r)return;
	if(y>=l&&y<=r)cnt++;
	if(yy>=l&&yy<=r)cnt++;
	think(f+"1","9"+b);
	think(f+"2","8"+b);
	think(f+"3","7"+b);
	think(f+"4","6"+b);
	think(f+"5","5"+b);
    think(f+"6","4"+b);
    think(f+"7","3"+b);
    think(f+"8","2"+b);
	think(f+"9","1"+b);
}
int main(){
	cin>>l>>r;
    if(5>=l && 5<=r)cnt++;
	think("1","9");
    think("2","8");
    think("3","7");
    think("4","6");
	think("5","5");
    think("6","4");
	think("7","3");
	think("8","2");
    think("9","1");
	cout<<cnt;
	return 0;
}
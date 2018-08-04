#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int r;
cin>>r;
vector<pair<int,int >>v;
int sm=INT_MAX;
for(int i=0; i<n ; i++)
{
	int f,s;
	cin>>f>>s;
	sm=min(sm,f);
	v.push_back({f,s});
}
set<int >a;
for(int i=sm ;i<=r;i++)
{
	bool f=false;
	for(int j=0;j<n;j++)
	{
		if(i>=v[j].first && i<=v[j].second)
		{
			f=true;
			break;
		}
	}
	if(!f)
	{
		a.insert(i);
	}

}
if(a.size()!=0){
cout<<a.size()<<"\n";
for(auto i: a)
	cout<<i<<" ";
}
else
cout<<a.size();


}
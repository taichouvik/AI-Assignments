/**
* Program to reach state:(2,3) from state:(0,0) in the water jug problem using recursion
* By- Vikalp Bhandari ,160102039 ,CSE A
**/

#include<bits/stdc++.h>
using namespace std;

//stores the answer states in reverse order
vector<pair<int,int>>v;

//stores if state is visited
map< pair<int,int>,int >m;
//dp[100][100]
// -1
// 1

//Function to find next valid state
bool next_state(int x,int y)
{

//check for termination/final state	
if(x==2 && y==3){
	v.push_back({2,3});
	return true;
}

//if current state already visited return false
if(m.find({x,y})!=m.end())
	return false;

//set current state as visited
m[{x,y}]=1;

//fill x
if(x<4){
	if(next_state(4,y)){
	v.push_back({x,y});
	return true;
	}
}

//empty x
if(x>0){
	if(next_state(0,y)){
		v.push_back({x,y});
		return true;
	}
}

//fill y
if(y<3){
	if(next_state(x,3)){
	v.push_back({x,y});
	return true;
	}
}

//empty y
if(y>0){
	if(next_state(x,0)){
		v.push_back({x,y});
		return true;
	}
}

//transfer to x and fill it upto brim
if(x+y>=4 && y>0){
	if(next_state(4,y-(4-x)) ){
		v.push_back({x,y});
		return true;
	}
}		

//transfer to y and fill it upto brim
if(x+y>=3 && x>0){
	if(next_state(x-(3-y),3) ){
		v.push_back({x,y});
		return true;
	}
}

//transfer to x and partially fill it
if(x+y<=4 && y>0){
	if(next_state(x+y,0) ){
		v.push_back({x,y});
		return true;
	}
}

//transfer to y and partial fill it
if(x+y<=3 && x>0){
	if(next_state(0,x+y) ){
		v.push_back({x,y});
		return true;
	}
}

//all conditions checked so return
return false;

}

int main(){

//call the function to calculate next states
next_state(0,0);

//size of 'v' gives no. of states
cout<<"Number of states ="<<v.size()<<"\n\n";

int index=1;
cout<<"S.No.\t" <<"X\t" <<"Y\n\n";

//print 'v' in reverse order 
for(auto i=v.rbegin();i!=v.rend();i++)
{
	cout<<index++<<"\t"<<i->first<<"\t"<<i->second<<"\n\n";
}

return 0;
}
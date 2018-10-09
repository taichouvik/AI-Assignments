/** 
* 4 Queens Problem - backtracking
* Vikalp Bhandari ,160102039 ,CSE A
* Given configuration
	q---
	-q--
	---q
	q---
**/
#include<bits/stdc++.h>
using namespace std;

int arr[][4]={{1,0,0,0},{0,1,0,0},{0,0,0,1},{1,0,0,0}};


int n=4;

//locate queen in given row
int locate(int i)
{
	for(int j=0;j<n;j++)
	{
		if(arr[i][j]==1)
			return j;
	}
}

//number of attacks in the board
int attack()
{
	int h=0;
	for(int p=0;p<n;p++){
	int x=p,y=locate(p);

	for(int i=0;i<n;i++)
	{
		if(i!=x){
			if(arr[i][y]==1)
				h++;
		}
	}
		
	for(int i=x,j=y;i<n && j<n;i++,j++)
	{
		if(i!=x)
		{
			if(arr[i][j]==1)
				h++;
		}

	}

	for(int i=x,j=y;i>=0,j>=0;i--,j--)
	{
		if(i!=x)
		{
			if(arr[i][j]==1)
				h++;
		}

	}

	for(int i=x,j=y;i>=0,j<n;i--,j++)
	{
		if(i!=x)
		{
			if(arr[i][j]==1)
				h++;
		}

	}

	for(int i=x,j=y;i<n,j>=0;i++,j--)
	{
		if(i!=x)
		{
			if(arr[i][j]==1)
				h++;
		}

	}
}

	return h;
}



//recursive backtracking
bool solve(int i)
{
	if(i==-1)
	{
		if(attack()==0)
		return true;

		return false;
	}
	int y=locate(i);

	for(int j=0;j<n;j++)
	{
		arr[i][y]=0;
		arr[i][j]=1;

		if( solve(i-1) ) 
			return true;
		
		//backtracking		
		arr[i][y]=1;
		arr[i][j]=0;
	}

	return false;
}



int main(){

//initial config
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	cout<<arr[i][j];
cout<<"\n";
}

solve(n-1);

cout<<"\nans\n";

//final config
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
	cout<<arr[i][j];
cout<<"\n";
}

return 0;	
}
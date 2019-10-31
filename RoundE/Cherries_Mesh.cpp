#include<iostream>
using namespace std;
int parent[200000];
struct Node{
	int node1;
	int node2;	
}lnode[200000];
int find(int a)
{
	  while(parent[a]>=0)a=parent[a];
	  return a;
}
int main()
{
	  int a, cherry, black;
	
	  cin >> a;
	  for(int index=1; index<=a; index++){
		  cin >> cherry >> black;
		  for(int i=0; i<black; i++) cin >> lnode[i].node1 >> lnode[i].node2;
		
		  for(int i=0; i<=cherry; i++) parent[i]=-1;
		
		  int side=0;
		  int result=0;
		  while(side<black){
			  int temp1=find(lnode[side].node1);
			  int temp2=find(lnode[side].node2);
			  if(temp1!=temp2){
				    if(parent[temp1]<parent[temp2]){
					    parent[temp1]+=parent[temp2];
					    parent[temp2]=temp1;
				    }
				    else{
					    parent[temp2]+=parent[temp1];
					    parent[temp1]=temp2;
				    }
				    ++result;
			    }
			    ++side;
		  }
		  result=result+(cherry-1-result)*2;
		  cout << "Case #" << index << ": " << result << endl;
	}
	return 0;
}

#include<iostream>
#include<set>
#include<map>
using namespace std;
int direction(char d)
{
	  int ans=0;
	  switch(d)
	  {
		  case 'E': 
			  ans=0;
			  break;
		  case 'W': 
			  ans=1;
			  break;
		  case 'N': 
			  ans=2;
			  break;
		  case 'S': 
			  ans=3;
			  break;
	  }
	  return ans;
}
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int main()
{
	  int a;
	  int dirn, row, col, curr, curc;
	  char dirc[50002];
	  set<pair<int,int> > visit;
	  map<pair<pair<int,int>,int>,pair<int,int> >  next_position;
	
	  cin >> a;
	  for(int index=1; index<=a; index++){
		    cin >> dirn >> row >> col >> curr >> curc;
		    cin >> dirc;
		    int mayber=curr;
		    int maybec=curc;
		
		    visit.insert({curr,curc});
		    for(int i=0; i<dirn; i++){
			      int curdir = direction(dirc[i]);
			      mayber+=dir[curdir][0];
			      maybec+=dir[curdir][1];
			
			      while(visit.find({mayber,maybec})!=visit.end()){        // find the next position
				        auto temp=next_position.find({{mayber,maybec},curdir});
				        if(temp!=next_position.end()){
					          mayber=temp->second.first;
					          maybec=temp->second.second;
				        }
				        else{
					          mayber+=dir[curdir][0];
					          maybec+=dir[curdir][1];
				        }
			      }
            
			      while(!(curr==mayber && curc==maybec)){                 //updated by the next position
				        auto temp=next_position.find({{curr,curc},curdir});
				        next_position[{{curr,curc},curdir}]={mayber,maybec};
				        if(temp!=next_position.end()){
					          curr=temp->second.first;
					          curc=temp->second.second;
				        }
				        else{
					          curr+=dir[curdir][0];
					          curc+=dir[curdir][1];
				        }  
			      }
			      visit.insert({curr,curc});
		    } 
		    cout << "Case #" << index << ": " << curr << " " << curc << endl;
		    visit.clear();
		    next_position.clear();
	  }
	  return 0;
}

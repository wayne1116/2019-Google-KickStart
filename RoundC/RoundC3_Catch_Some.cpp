#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf= 500000000;
int dp[1024][1024][2];
int color_position[1024][1024];

int main()
{
	  int a;
	  int n, observe;
		
	  cin >> a;
	  for(int index=1; index<=a; index++){
		    cin >> n >> observe;
		    vector<int> position(n);
		    vector<int> color(n);
		    for(int i=0; i<n; i++) cin >> position[i];
		    for(int i=0; i<n; i++) cin >> color[i];
		
		    vector<int> comp=color;
		    sort(comp.begin(),comp.end());
		    comp.erase(unique(comp.begin(),comp.end()),comp.end());                     // delete duplicate numbers
		    for(int i=0; i<n; i++){                                                     // change the index of the color
			      color[i]=lower_bound(comp.begin(),comp.end(),color[i])-comp.begin()+1;
		    }    
		
		    int color_number=comp.size();
		    vector<vector<int> > temp(color_number+1);
		
		    for(int i=0; i<n; i++){                              
			      temp[color[i]].push_back(position[i]);
		    }
		
		    for(int i=1; i<=color_number; i++){
			      sort(temp[i].begin(),temp[i].end());
		    }
		
		    for(int i=0; i<=color_number; i++){                                //initialization
			      color_position[i][0]=0;
			      for(int j=1; j<=observe; j++) color_position[i][j]=inf;
		    }
		
		    for(int i=1; i<=color_number; i++){
			      for(int j=0; j<temp[i].size(); j++){
				        color_position[i][j+1]=temp[i][j];
			      }
			      temp[i].clear();
		    }
		
		    for(int i=0; i<=color_number; i++){
			      dp[i][0][0]=dp[i][0][1]=0;
			      for(int j=1; j<=observe; j++) dp[i][j][0]=dp[i][j][1]=inf;
		    }
		
		    // dp[i][j][0]: need to observe j dogs and then retrun home
		    for(int i=1; i<=color_number; i++){                   
			      for(int j=1; j<=observe; j++){                    
				        dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]);
				        int l=1;                                          
				        for(int k=j-1; k>=0; k--, l++) dp[i][j][0]=min(dp[i][j][0],dp[i-1][k][0]+2*color_position[i][l]); 
  			    }                                              
		    }
		
		    // dp[i][j][1]: has either observed or has decided to observe the last dog 
		    for(int i=1; i<=color_number; i++){ 
			      for(int j=1; j<=observe; j++){
				        dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]);
				        int l=1;                                                                  
				        for(int k=j-1; k>=0; k--, l++) dp[i][j][1]=min(dp[i][j][1],dp[i-1][k][0]+color_position[i][l]);				
				
				        dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
				        l=1;
				        for(int k=j-1; k>=0; k--, l++) dp[i][j][1]=min(dp[i][j][1],dp[i-1][k][1]+2*color_position[i][l]);
			      }
		      }
		      cout << "Case #" << index << ": " << dp[color_number][observe][1] << endl;		
	  }
	  return 0;
} 

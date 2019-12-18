#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	  int a;
	  int index;
	  int total;
	  int start;
	  int i, j, k, m;
	  int num[10];
	  bool dp[256][256][11];
	  string result;
    
	  cin >> a;
	  for(int index=1; index<=a; index++){
		  total=0;
		  for(int i=1; i<=9; i++){
			  cin >> num[i];
		  	if(num[i]>20){
				  if(num[i]&1) num[i]=20;
				  else num[i]=21;
			  }  
			  total+=num[i];
		  }
		  memset(dp, false, sizeof(dp));
		
		  dp[0][0][0]=true;
		  start=0;
		  for(int i=1; i<=9; i++){
			  for(int j=1; j<=num[i]; j++){
				  for(int k=0; k<=total/2; k++){
					  for(int m=0; m<11; m++){
						  dp[start+j][k+1][(m+i)%11] |= dp[start+j-1][k][m];   // add in the positive partition
						  dp[start+j][k][(m-i+11)%11] |= dp[start+j-1][k][m];  // add in the negative partition
					  }
				  }
			  }
			  start+=num[i];
		  }
		
		  if(dp[total][total/2][0]) result="Yes";
		  else result="No";
		  cout << "Case #" << index << ": " << result << endl; 
	  }
	  return 0;
}

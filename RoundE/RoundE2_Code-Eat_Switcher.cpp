#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node{
	  double code;
	  double eat;
	  double ratio;
}lnode[200000];
bool cmp(const struct Node &x, const struct Node &y)
{
	  return y.ratio>x.ratio;
}
int main()
{
	  int a;
	  int day, slot;
	  double code, eat;
	  double totaleat, totalcode;
	  cin >> a;
	  for(int index=1; index<=a; index++){
		    //cout << "Case #" << index << ": ";
		    cin >> day >> slot;
		    totaleat=totalcode=0;
		    for(int i=0; i<slot; i++){
			      cin >> lnode[i].code >> lnode[i].eat;
			      totaleat+=lnode[i].eat;
			      totalcode+=lnode[i].code;
			      lnode[i].ratio=lnode[i].eat/lnode[i].code;
		    }
		    sort(lnode,lnode+slot,cmp);
		
        	    vector<double> dp(slot);
		    vector<double> dp1(slot);
		    dp[0]=lnode[0].eat;
		    dp1[0]=lnode[0].code;
		    for(int i=1; i<slot; i++){
			      dp[i]=dp[i-1]+lnode[i].eat;
			      dp1[i]=dp1[i-1]+lnode[i].code;
		    }

		    char result[200000];
		    result[day]='\0';
		    for(int i=0; i<day; i++){
			      cin >> code >> eat;
			      if(totaleat<eat || totalcode<code){
				        result[i]='N';
				        continue;
		    	      }
			      double diff=totaleat-eat;
			      auto temp=upper_bound(dp.begin(),dp.end(), diff);
			      int position = (temp-dp.begin());

			      double temp1 = (position>0)?dp1[position-1]:0;
			      double diff1= diff-(dp[position]-lnode[position].eat);
			      temp1+=(diff1/lnode[position].ratio);
			      if(temp1>=code) result[i]='Y';
			      else result[i]='N';
		    }
		    cout << "Case #" << index << ": " << result << endl;
	}
	return 0;
}

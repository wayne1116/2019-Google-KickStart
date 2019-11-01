#include<vector>
#include<algorithm>
#include<set>
using namespace std;
bool biteven(int a)
{
	  int count=0;
	  for(int i=0; i<10; i++){
		    if(a&1) ++count;
		    a=a>>1;
	  }
  	return count&1==1?false:true;
}

int main()
{
	  int a, n, q;
	  int pos, value;
	  int number;

	  cin >> a;
	  for(int index=1; index<=a; index++){
		    cin >> n >> q;
		
		  set<int> oddlocation;
		  for(int i=0; i<n; i++){
			    cin >> number;
			    if(!biteven(number)) oddlocation.insert(i);			
		  }
		
		  vector<int> result;
		  while(q--){
			    cin >> pos >> value;

			    auto iter=oddlocation.find(pos);
			    bool temp=biteven(value);
			    if(iter!=oddlocation.end() && temp) oddlocation.erase(iter);
		      else if(iter==oddlocation.end() && !temp) oddlocation.insert(pos);	

			    if(oddlocation.size()%2==0) result.push_back(n);
			    else{
				      auto temp1=oddlocation.begin();
				      auto temp2=oddlocation.end(); --temp2;

				      int Max=0;
				      //Max=max(Max, *temp1);
				      Max=max(Max, n-*temp1-1);
				      Max=max(Max, *temp2);
				      //Max=max(Max, n-*temp2-1);
				      result.push_back(Max);
			    }
		  }
		  cout << "Case #" << index << ":";
		  for(int i=0; i<result.size(); i++) cout << " " << result[i];
		  cout << endl;
	}
	return 0;
}

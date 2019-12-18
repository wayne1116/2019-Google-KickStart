#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	  vector<int> vect;
	  vector<int> result;
	  vector<int>::iterator it; 
	  int a, cnt, citation;
	
	  cin >> a;
	  for(int index=1; index<=a; index++){
		  result.clear();	
		  vect.clear();
		  cin >> cnt;
		  int citnumber=1;
		  for(int i=0; i<cnt; i++){
			  cin >> citation;
			  it=lower_bound(vect.begin(), vect.end(), citation);
			  vect.insert(it, citation);
			  it=lower_bound(vect.begin(), vect.end(), citnumber);
			  int temp = vect.end()-it;
			  if(citnumber<=temp){
				  result.push_back(citnumber);
				  ++citnumber;
			  }
			  else result.push_back(citnumber-1);
		  }
		  cout << "Case #" << index << ":"; 
		  for(int i=0; i<cnt; i++) cout << " " << result[i]; 
		  cout << endl;
	  }
	  return 0;
}

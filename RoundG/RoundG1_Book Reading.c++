#include<iostream>
using namespace std;
int main()
{
	  int a;
	  int bookpage, tornpage, people;
	  int torn, readpage, result, mul;
	  bool tag[100001];
	  cin >> a;
	  for(int index=1; index<=a; index++){
		    cin >> bookpage >> tornpage >> people;
		    for(int i=1; i<=bookpage; i++) tag[i]=true;
		    for(int i=0; i<tornpage; i++){
			    cin >> torn;
			    tag[torn]=false;
		    }		
		    result=0;
		    for(int i=0; i<people; i++){
			    cin >> readpage;
			    if(readpage==1) result=result+bookpage-tornpage;
			    else{
				    mul=1;
				    while(readpage*mul<=bookpage){
					    if(tag[readpage*mul]) ++result;
					    ++mul;
				    }
			    }
		    } 
		    cout << "Case #" << index << ": " << result << endl;
	  }
	  return 0;
}

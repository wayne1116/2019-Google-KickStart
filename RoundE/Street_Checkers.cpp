#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAX=1000000000;
int main()
{
	vector<int> prime;
	int limit=(int)sqrt(MAX);
	int i, j;

	prime.push_back(2);
	for(i=3; i<=limit; i+=2){                           // find the prime number
		int limit1=(int)sqrt(i);
		for(j=3; j<=limit1; j+=2) if(i%j==0) break;
		if(j>limit1) prime.push_back(i);           // store the prime number
	}

	int a;
	int left, right;	
	int result=0;

	cin >> a;
	for(int index=1; index<=a; index++){
		cin >> left >> right;
		result=0;
		for(i=left; i<=right; i++){
			if(i%2==0){                              // three sub case
				int temp=i;
				int count=0;
				while(temp%2==0){
					++count;
					temp=temp>>1;
				}
				
				if(i==8) ++result;
				else if(count==2){
					bool flag=true;
                                	for(j=0; j<prime.size(); j++){     // determine whether temp is the prime number
                                        	if(temp<=prime[j]) break;
                                        	else if(temp%prime[j]==0){
                                                	flag=false;
                                                	break;
                                        	}
                                	}
                                	if(flag) ++result;
				}
				else if(count<2) ++result;
			}
			else{
				bool flag=true;
				for(j=0; j<prime.size(); j++){     // determine whether i is the prime number
					if(i<=prime[j]) break;
					else if(i%prime[j]==0){
						flag=false;
						break;
					}
				}
				if(flag) ++result;
			}
		}
		cout << "Case #" << index << ": " << result << endl;
	}
	return 0;
}

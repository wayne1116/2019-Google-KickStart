#include<iostream>
using namespace std;
long long value[1024];
long long choose(int a, int b)
{
	if(a>=b) return 0;
	return 1;
}
int main()
{
	int a;
	long long n, limit;
	
	cin >> a;
	for(int index=1; index<=a; index++){
		cin >> n >> limit;
		for(int i=0; i<n; i++) cin >> value[i];
		
		long long sure = 0;
		for(int i=50; i>=0; i--){
			int count = 0;
			for(int j=0; j<n; j++){
				if((1LL<<i)&value[j]) ++count;
			}
			if(count>=n-count) sure|=(1LL<<i);
		}
		long long temp2=0;
		long long result=-1;
		for(int j=0; j<n; j++) temp2=temp2+(value[j]^sure);
		if(temp2<=limit){	
			for(int i=50; i>=0; i--){
				int count = 0;
				for(int j=0; j<n; j++){
					if((1LL<<i)&value[j]) ++count;
				}
				long long temp=sure+(1LL<<i)*choose(count,n-count);
				long long temp1=0; 
				for(int j=0; j<n; j++) temp1=temp1+(value[j]^temp);
				if(temp1<=limit) sure=temp;
			}
			result=sure;
		}
		cout << "Case #" << index << ": " << result << endl;
	}
	return 0;
} 

/*
example 1

step1: 
	  8 	1 0 0 0
    4   0 1 0 0
    2   0 0 1 0
       ---------
        0 0 0 0  -> minimum possible value

step2:(change the bit from most significant bit)
        1 0 0 0 -> ok
        1 1 0 0 -> ok
        1 1 1 0 -> no 
        1 1 0 1 -> no

ans:    1 1 0 0
*/

#include<iostream>
using namespace std;
int main()
{
	int a, n, limit, temp;
	int item[100002];
	int number[100002];
	bool flag[100002];
	int Max;
	cin >> a;
	for(int c=1; c<=a; c++){
		cin >> n >> limit;
		for(int i=0; i<n; i++) cin >> item[i];
		Max=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<100002; j++) {
				number[j]=0;
				flag[item[j]]=true;
			}
			temp=0;
			for(int j=i; j<n; j++){
				++number[item[j]];
				if(number[item[j]]<=limit) ++temp;
				else{
					//cout << "---" << item[j] << " " << temp << endl;
					if(flag[item[j]]) temp=temp-number[item[j]]+1;
					flag[item[j]]=false;
				}
				if(Max<temp) Max=temp;
			}
			//cout << "---" << temp << endl;
			if(Max<temp) Max=temp;
			//cout << Max << endl;
		}
		cout << "Case #" << c << ": " << Max << endl; 
	}
	return 0;
}


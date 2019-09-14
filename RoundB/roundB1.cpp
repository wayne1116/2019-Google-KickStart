#include<iostream>
using namespace std;
int count[100002][26];
int main()
{
	int a, len, question, result;
	int count1[32];
	string line;
	cin >> a;
	for(int c=1; c<=a; c++){
		cin >> len >> question >> line;
		result=0;
		for(int i=0; i<26; i++) count[0][i]=0;
		for(int i=1; i<=len; i++){
			for(int j=0; j<26; j++) count[i][j]=count[i-1][j];
			++count[i][line[i-1]-'A'];
		}
		//for(int i=1; i<=len; i++){
		//	for(int j=0; j<26; j++) cout << count[i][j] << " ";
		//	cout << endl;
		//}
		while(question--){
			int s, e;
			cin >> s >> e;
			int len1=e-s+1;
			for(int i=0; i<26; i++) count1[i]=count[e][i]-count[s-1][i];
			if(len1%2==0){
				bool flag=true;
				for(int i=0; i<26; i++){
					if(count1[i]%2){
						flag=false;
						break;
					}
				}
				if(flag) ++result;
			}
			else{
				bool flag=true, flag1=false;
				for(int i=0; i<26; i++){
					if(flag1 && count1[i]%2){
						flag=false;
						break;
					}
					else if(count1[i]%2) flag1=true; 
				}
				if(flag) ++result;
			}
		}
		cout << "Case #" << c << ": " << result << endl;
	} 
	return 0;
}

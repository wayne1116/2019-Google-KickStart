#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int &x, int &y)
{
	return y>x;
}
int num[100001];
int main()
{
	int a, n, pick, i;
	int left, result=0;
	int temp, temp1, case1=1, mul;
	cin >> a;
	while(a--){
		cin >> n >> pick;
		for(i=0; i<n; i++){
			cin >> num[i];
		}
		sort(num,num+n,cmp);
		cout << "Case #" << case1++ << ": ";
		result=0;
		for(i=0; i<pick; i++) result+=num[pick-1]-num[i];
		left=0;
		mul=pick-1;
		temp=result;
		for(i=pick; i<n; i++){
			temp=temp-num[i-1]+num[left]+mul*(num[i]-num[i-1]);
			if(temp<result) result=temp;
			++left;
		}
		cout << result << endl;
	}
	return 0;
} 

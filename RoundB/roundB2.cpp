#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
const int sumtime=10010;
struct Node{
	int time;
	int engine;
	int lose;
}lnode[128];
int dp[sumtime], dp1[sumtime];
bool cmp(struct Node &x, struct Node &y)
{
	return y.time*x.lose>x.time*y.lose;
}
int main()
{
	int a, n;
	cin >>a;
	for(int c=1; c<=a; c++){
		cin >> n;
		for(int i=0; i<n; i++) cin >> lnode[i].time >> lnode[i].engine >> lnode[i].lose;
		sort(lnode,lnode+n,cmp);
		
		memset(dp,0,sizeof dp);
		memset(dp1,0,sizeof dp1);
		int time=0;
		for(int i=0; i<n; i++){
			time+=lnode[i].time;
			for(int j=0; j<=time; j++) dp1[j]=dp[j];
			for(int j=lnode[i].time; j<=time; j++){
				int engine=lnode[i].engine-(j-lnode[i].time)*lnode[i].lose;
				if(engine<=0) continue;
				dp[j]=max(dp[j],dp1[j-lnode[i].time]+engine);
			}
		}
		int result=0;
		for(int i=0; i<=time; i++) result=max(result,dp[i]);
		cout << "Case #" << c << ": " << result << endl;
	}
	return 0;
}

/*
解題思路 
假設找到一個最佳解opt
而吃石頭的順序為s1,s2,......,sn
其中si,sj且i<j
vi=ei-t*li+ej-(t+ti)*lj
vj=ej-t*lj+ei-(t+tj)*li
滿足特性ti*lj<tj*li 
所以說ti*lj較小的相對順序一定比較前面
但絕對順序不確定->使用0/1 Knapsack 
*/

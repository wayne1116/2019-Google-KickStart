#include<iostream>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;
const int N=255;
int n,m;
int row, col;
string g[N];
int dist[N][N];

void bfs(int k)  //遍歷從post office出發往外k個位置 
{
	queue<pair<int,int> > q;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++) dist[i][j]=-1;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(g[i][j]=='1'){
				dist[i][j]=0;
				q.push({i,j});
			}
		}
	}
	int dx[4]={-1,0, 1, 0}, dy[4]={0,1,0,-1};
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		int x=t.first, y=t.second;
		int distance=dist[x][y];
		if(k==distance) continue;
		for(int i=0; i<4; i++){
			int a=x+dx[i], b=y+dy[i];
			if(a>=0 && a<row && b>=0 && b<col && dist[a][b]==-1){
				dist[a][b]=dist[x][y]+1;
				q.push({a,b}); 
			} 
		}
	}
}
bool check(int k)
{
	bfs(k);
	int min_sum=INT_MAX, max_sum=INT_MIN;
	int min_sub=INT_MAX, max_sub=INT_MIN;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(dist[i][j]==-1)               //找出相距最遠的兩端點 
			{
				min_sum=min(min_sum, i+j);
				max_sum=max(max_sum, i+j);
				min_sub=min(min_sub, i-j);
				max_sub=max(max_sub, i-j);
			}
		}
	}
	
	if(min_sum==INT_MAX) return true; //代表k設太大，從post office到任何一點都能被包含 
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(g[i][j]=='0'){
				int sum=max(abs(i+j-min_sum),abs(i+j-max_sum));
				int sub=max(abs(i-j-min_sub),abs(i-j-max_sub));
				if(max(sum,sub)<=k) return true;
			}
		}
	}
	return false;
	
}
int main()
{
	int a, c;
	cin >> a;
	for(c=1; c<=a; c++){
		cin >> row >> col;
		for(int i=0; i<row; i++) cin >> g[i];
		
		int left=0, right=row+col;
		while(left<right){
			int mid=(left+right)>>1;
			if(check(mid)) right=mid;
			else left=mid+1;
		} 
		cout << "Case #" << c << ": " << right << endl;
	}
	return 0;	
} 

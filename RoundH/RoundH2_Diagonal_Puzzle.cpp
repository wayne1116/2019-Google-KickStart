#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
struct Node{
		int diagonal1;
		int diagonal2;
}lnode[512][512];
char grid[512][512];
int graph[512][512][2];
bool v[512];
int calcflip1;
int calcflip2;
int vertic;

void dfs(int current_node, bool prevflipstate, bool connstate)
{
		bool flip=false;
		v[current_node]=true;
		// prevflipstate: whether the previous diagonal flipped
		// connstate: the point of intersection is '#'(true) or '.'(false)
		// Two case the current diagonal have to flip:
		// 1. When previous diagonal flipped and the point of intesection is '#'
		// 2. When previous diagnoal flipped and the point of intesection is '.' 
		if(prevflipstate && connstate || !prevflipstate && !connstate) flip=true;  
		if(flip) ++calcflip1;
		else ++calcflip2;

		for(int i=0; i<vertic; i++){
			if(!v[i] && graph[current_node][i][0]!=-1){
				int x=graph[current_node][i][0];
				int y=graph[current_node][i][1];
				bool mark=false;
				if(grid[x][y]=='#') mark=true;
				dfs(i, flip, mark);
			}
		}
}

int main()
{
		int a, n;
		int i, j;
		int index;
		int srow, scol;
		
		cin >> a;
		for(int index=1; index<=a; index++){
			cin >> n;
			for(int i=0; i<n; i++) cin >> grid[i];

			vertic=0;
			for(int i=0; i<n; i++){
				srow=0;
				scol=i;
				while(scol>=0){
					lnode[srow][scol].diagonal1=vertic;						
					++srow; 
					--scol;
				}
				++vertic;
			}

			for(int i=1; i<n; i++){
				srow=i;
				scol=n-1;
				while(srow<n){
					lnode[srow][scol].diagonal1=vertic;
					++srow;
					--scol;
				}
				++vertic;
			}

			for(int i=0; i<n; i++){
				srow=i;
				scol=n-1;
				while(srow>=0){
					lnode[srow][scol].diagonal2=vertic;
					--srow;
					--scol;
				}
				++vertic;
			}

			for(int i=1; i<n; i++){
				srow=i;
				scol=0;
				while(srow<n){
					lnode[srow][scol].diagonal2=vertic;
					++srow;
					++scol;
				}
				++vertic;
			}
                
			memset(graph, -1, sizeof(graph));
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					// point of intersection
					int temp1=lnode[i][j].diagonal1; 
					int temp2=lnode[i][j].diagonal2;
					graph[temp1][temp2][0]=i;
					graph[temp1][temp2][1]=j;
					graph[temp2][temp1][0]=i;
					graph[temp2][temp1][1]=j;
				}
			}

			memset(v, false, sizeof(v));
			int result=0;
			for(int i=0; i<vertic; i++){
				if(!v[i]){
					v[i]=true;      // visited i-th diagonal
					calcflip1=0;    // flip
					calcflip2=1;    // not flip
					for(int j=0; j<vertic; j++){                   // whether j-th diagonal is intersected by i-th diagonal
						if(!v[j] && graph[i][j][0]!=-1){
							int x=graph[i][j][0];
							int y=graph[i][j][1];
							bool mark=false;
							if(grid[x][y]=='#') mark=true;
							dfs(j, false, mark);           // calculate
						}
					}
					result=result+min(calcflip1, calcflip2);
				}
			}
			cout << "Case #" << index << ": " << result << endl;
		}
		return 0;
}

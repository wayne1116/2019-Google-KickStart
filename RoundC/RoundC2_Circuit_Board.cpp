#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a;
	int row, col, dthick;
	int board[301][301];
	int dp[301][301];
	int Min, Max;
	
	cin >> a;
	for(int index=1; index<=a; index++){
		cin >> row >> col >> dthick;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cin >> board[i][j];
			}
		}
		
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				Min=board[i][j];
				Max=board[i][j];
				int k; 
				for(k=j+1; k<col; k++){                 // each row
					Min=min(Min, board[i][k]);
					Max=max(Max, board[i][k]);
					if(Max-Min>dthick) break;      
				}
				dp[i][j]=k-j;
			}
		}
		
		int result=row;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				int k;
				Min=dp[i][j];
				for(k=i; k<row; k++){
					Min=min(Min, dp[k][j]);
					result=max(result,(k-i+1)*Min);
				}
			}
		}
		cout << "Case #" << index << ": " << result << endl;
	}
	return 0;
}

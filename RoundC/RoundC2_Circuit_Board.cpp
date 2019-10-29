#include<stdio.h>
#include<stdlib.h>
int min(int a, int b)
{
	return a>b?b:a;
}
int max(int a, int b)
{
	return a>b?a:b;
}
int main()
{
	int a, i, j, k;
	int row, col, diff;
	int Min, Max;
	int result, index=1;
	int map[301][301];
	int temp[301][301];
	
	scanf("%d",&a);
	while(a--){
		scanf("%d%d%d",&row,&col,&diff);
		for(i=0; i<row; i++){
			for(j=0; j<col; j++) scanf("%d",&map[i][j]);
		} 
		
		for(i=0; i<row; i++){                 //A circuit board is good if in each row,
			for(j=0; j<col; j++){         //the difference between the thickest square 
				Min=map[i][j];        //and the least thick square is no greater than K.
				Max=map[i][j];
				for(k=j+1; k<col; k++){
					Min=min(Min,map[i][k]);
					Max=max(Max,map[i][k]);
					if(Max-Min>diff) break;
				}
				temp[i][j]=k-j;
			}
		}
		
		result=row;
		for(i=0; i<row; i++){                  // calculate the columns and find a good subcircuit board
			for(j=0; j<col; j++){
				Min=temp[i][j];
				for(k=i; k<row; k++){
					Min=min(Min,temp[k][j]);
					result=max(result, Min*(k-i+1));
				}	
			}
		}
		printf("Case #%d: %d\n", index++, result); 
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int r[128][128];
int diff[128];
int f[128][128];

int F(int cur, int change)
{
    int value=1000000;
    // when the number of places where the sections from 0 to x has Ai ≠ Ai+1 is less than the change.
    if(diff[cur]<=change) return 0;
    // when the change is 0 -> the height from 0 to cur sections must be equal. 
    if(change==0) return r[0][cur];
    for(int i=0; i<cur; i++){
        if(f[i][change-1]<0) f[i][change-1]=F(i, change-1);
        value=min(value, f[i][change-1]+r[i+1][cur]);
    }
    return value;
}
int main()
{
    int a;
    int n;
    int count;
    int change;
    int result;
    int maxcount;
    int mode;
    int wall[128];

    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> n >> change;
        for(int i=0; i<n; i++) cin >> wall[i];
        memset(r, 0, sizeof(r));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) f[i][j]=-1;
        }
        // r(i,j): defines number of removals necessary to 
        // have all wall sections from i to j have the same height.
        // diff[x]: defines the number of places where the sections from 0 to x has Ai ≠ Ai+1   
        diff[0]=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                maxcount=0;
                for(int k=i; k<=j; k++){
                    int num=wall[k];
                    count=0;
                    // calcuate the mode between i and j sections
                    for(int l=i; l<=j; l++) if(num==wall[l]) ++count;
                    if(count>maxcount){
                        maxcount=count;
                        mode=num;
                    }
                }
                count=0;
                for(int k=i; k<=j; k++) if(mode!=wall[k]) ++count;
                r[i][j]=count;
            }
            if(i>0){
                if(wall[i-1]!=wall[i]) diff[i]=diff[i-1]+1;
                else diff[i]=diff[i-1];
            }
        }
        // F(x,k): defines the number of the walls we need to remove 
        // so that the sections from 0 to x-1 sections in the input has Ai ≠ Ai+1 in at most k places.
        // f(x,k): record the information which F(x,k) had calculated.
        result=F(n-1, change);
        cout << "Case #" << index << ": " << result << endl;
    }
    return 0;
}

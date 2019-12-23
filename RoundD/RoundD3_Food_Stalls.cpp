#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<cstring>
#include<iomanip>
#include<float.h>
using namespace std;

struct Node{
    double dis;
    double cost;
}lnode[100002];
double mincost[100002];
bool cmp(const struct Node &x, const struct Node &y)
{
    return y.dis>x.dis;
}
void ans1(int limit, int spot, int stall)
{   
    priority_queue<double> qu;
    double sum=0;
    int warehouse=limit;
        
    for(int i=0; i<limit; i++){
        //Maintain a max-heap of size floor(K/2). For position i, 
        //we define Vi = XN - Xi + Ci. Initially, we will store V0, V1, ..., Vfloor(K/2)-1 in our heap. 
        //We'll also maintain the sum of all the elements in our heap.
        qu.push(lnode[spot-1].dis-lnode[i].dis+lnode[i].cost);
        sum+=lnode[spot-1].dis-lnode[i].dis+lnode[i].cost;
    }
    //Consider that we are placing the warehouse at Xfloor(K/2), 
    //then the minimum cost of placing all floor(K/2) stalls to the left of 
    //it is given by sum of all the elements in our heap - floor(K/2) * (XN - Xfloor(K/2)).
    mincost[warehouse]=sum-limit*(lnode[spot-1].dis-lnode[warehouse].dis);

    for(int i=limit; i<spot-(stall-limit)-1; i++){
        //Check if Vi is less than the maximum element of our heap.
        //If it is then we remove the maximum and insert Vi and update the sum of all our heap elements 
        //by subtracting the difference of the removed element and the inserted element.
        double v=lnode[spot-1].dis-lnode[i].dis+lnode[i].cost;
        double temp=qu.top();
        if(temp>v){
            qu.pop();
            qu.push(v);
            sum=sum-temp+v;
        }
        //We subtract floor(K/2) * (XN - Xi+1) from the sum and compare it with the minimum cost obtained thus far
        warehouse=i+1;
        mincost[warehouse]=sum-limit*(lnode[spot-1].dis-lnode[warehouse].dis);
    }
    while(!qu.empty()) qu.pop();
}
void ans2(int limit, int spot, int stall)
{
    if(limit==0) return;   
    priority_queue<double> qu;
    double sum=0;
    int warehouse=spot-limit-1;
        
    for(int i=spot-1; i>warehouse; i--){
        //maintain a max-heap of size stall-floor(K/2). For position i, 
        //we define Vi = Xi + Ci. Initially, we will store Vspot-1, Vspot-2, ..., Vspot-floor(K/2) in our heap. 
        //We'll also maintain the sum of all the elements in our heap.
        qu.push(lnode[i].dis+lnode[i].cost);
        sum+=lnode[i].dis+lnode[i].cost;
    }
    //Consider that we are placing the warehouse at Xspot-floor(K/2), 
    //then the minimum cost of placing all spot-floor(K/2) stalls to the right of 
    //it is given by sum of all the elements in our heap - (spot-floor(K/2)) * Xspot-floor(K/2).
    mincost[warehouse]+=sum-limit*lnode[warehouse].dis;

    for(int i=warehouse; i>stall-limit; i--){
        //Check if Vi is less than the maximum element of our heap.
        //If it is then we remove the maximum and insert Vi and update the sum of all our heap elements 
        //by subtracting the difference of the removed element and the inserted element.
        double v=lnode[i].dis+lnode[i].cost;
        double temp=qu.top();
        if(temp>v){
            qu.pop();
            qu.push(v);
            sum=sum-temp+v;
        }
        //We subtract (spot-floor(K/2)) * (Xi-1) from the sum and compare it with the minimum cost obtained thus far
        warehouse=i-1;
        mincost[warehouse]+=sum-limit*lnode[warehouse].dis;
    }
    while(!qu.empty()) qu.pop();
}
int main()
{
    int a, i, j;
    int index;
    int stall;
    int spot;
    int limit;
    int warehouse1;
    int warehouse2;
    double result;
    priority_queue<double, vector<double>, greater<double> > qu;

    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> stall >> spot;
        for(int i=0; i<spot; i++) cin >> lnode[i].dis;
        for(int i=0; i<spot; i++) cin >> lnode[i].cost;
        for(int i=0; i<spot; i++) mincost[i]=DBL_MAX;
        limit=(stall+1)>>1;
        sort(lnode, lnode+spot, cmp);
        ans1(limit, spot, stall);        // left  : floor(K/2)
        ans2(stall-limit, spot, stall);  // right : stall-floor(K/2)

        result=DBL_MAX-1;
        for(int i=limit; i<=spot-(stall-limit)-1; i++){
            mincost[i]+=lnode[i].cost;
            result=(result>mincost[i])?mincost[i]:result;
        }
        cout << "Case #" << index << ": " << fixed << setprecision(0) << result << endl;
    }
    return 0;
}

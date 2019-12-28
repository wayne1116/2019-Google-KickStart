#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
struct Node{
    int n;
    long long skill[5];
}lnode[50001];
stack<long long> st;
map<long long, int> hashmap;
long long number[5];
long long skillnumber;
// find the subset and calcuate the hash value
void calchash(int index, int s, int n)
{
    if(s==n){
        stack<long long> tmp;
        int count=0;
        while(!st.empty()){
            long long num=st.top();
            tmp.push(num);
            number[count++]=num;
            st.pop();
        }
        sort(number, number+count);
        long long hash=0;
        for(int i=0; i<count; i++) hash=hash*(skillnumber+1)+number[i];
        
        hashmap[hash]+=1;
        while(!tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
        return;
    }
    st.push(lnode[index].skill[s]);
    calchash(index, s+1, n);
    st.pop();
    calchash(index, s+1, n);
}
int main()
{
    int a;
    int total;

    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> total >> skillnumber;
        for(int i=0; i<total; i++){
            int m;
            cin >> m;
            for(int j=0; j<m; j++) cin >> lnode[i].skill[j];
            lnode[i].n=m;
        } 

        // map the every subset of Ai to the hash value
        hashmap.clear();
        for(int i=0; i<total; i++){
            int m=lnode[i].n;
            calchash(i, 0, m);
        }
        long long result=0;
        for(int i=0; i<total; i++){
            int m=lnode[i].n;
            sort(lnode[i].skill, lnode[i].skill+m);
            long long hashvalue=0;
            // calculate the hash value of the Ai
            for(int j=0; j<m; j++) hashvalue=hashvalue*(skillnumber+1)+lnode[i].skill[j];
            // the corresponding hash value indicate that who also has the skills
            result+=total-hashmap[hashvalue];
        }
        cout << "Case #" << index << ": " << result << endl;
    }
    return 0;
}

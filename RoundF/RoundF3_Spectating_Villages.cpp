#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
vector<int> vect[100000];
ll value[100000];
bool bdp[100000][2][2];
ll dp[100000][2][2];

// prev_light: indicate whether the parent node of K has a lighthouse
// cur_light: indicate whether current node K has a lighthouse
ll solv(int current, int prev_light, int cur_light, int parent_node)
{   
    // memorized result from previous calculation 
    if(bdp[current][prev_light][cur_light])
        return dp[current][prev_light][cur_light];

    // Case 1 & 2: (prev_light=1, cur_light=1) & (prev_light=0, cur_light=1)
    if(cur_light==1) {
        ll v = 0;
        for(int i=0; i<vect[current].size(); i++) {
            if(parent_node!=vect[current][i])
                v += max(solv(vect[current][i], 1, 0, current), solv(vect[current][i], 1, 1, current));
        }

        bdp[current][prev_light][cur_light] = true;
        dp[current][prev_light][cur_light] = v + value[current];
        return v + value[current]; 
    }
    // Case 3: (prev_light=1, cur_light=0)
    else if(prev_light==1) {
        ll v = 0;
        for(int i=0; i<vect[current].size(); i++) {
            if(parent_node!=vect[current][i])
                v += max(solv(vect[current][i], 0, 0, current), solv(vect[current][i], 0, 1, current));
        }

        bdp[current][prev_light][cur_light] = true;
        dp[current][prev_light][cur_light] = v + value[current];
        return v + value[current];
    }
    // Case 4: (prev_light=0, cur_light=0)
    if(vect[current].size()==1 && parent_node>=0) 
        return 0;
    
    int n = vect[current].size()-1;
    int index = 0;
    ll dp0 = 0;
    ll dp1 = 0;
    for(int i=0; i<vect[current].size(); i++) {
        if(parent_node!=vect[current][i]) {
            ll v1 = solv(vect[current][i], 0, 0, current);
            ll v2 = solv(vect[current][i], 0, 1, current);
            if(index>0) {
                dp1 = max(dp1+max(v1, v2), dp0+v2);
                dp0 = dp0 + v1;
            }
            else{
                dp0 = v1;
                dp1 = v2;
            }
            ++index;
        }
    }
    bdp[current][prev_light][cur_light] = true;
    dp[current][prev_light][cur_light] = max(dp1+value[current], dp0);
    return max(dp1+value[current], dp0);
}

int main()
{
    int a, n;

    cin >> a;
    for(int index=1; index<=a; index++) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> value[i];
            bdp[i][0][0] = bdp[i][0][1] = false;
            bdp[i][1][0] = bdp[i][1][1] = false;
        }
        
        for(int i=0; i<n-1; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            vect[node1-1].push_back(node2-1);
            vect[node2-1].push_back(node1-1);
        }
        
        ll result = max(solv(0, 0, 1, -1), solv(0, 0, 0, -1));
        cout << "Case #" << index << ": " << result << endl; 
        
        for(int i=0; i<n; i++)
            vect[i].clear();
    }
    return 0;
}

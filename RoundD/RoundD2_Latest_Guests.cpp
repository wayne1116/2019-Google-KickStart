#include<iostream>
#include<cstring>
#include<set>
#include<map>
using namespace std;
// record the clockwise guests
map<int,bool> clockwise;
// record the anti_clockwise guests
map<int,bool> anti_clockwise;
// record consulates where the clockwise guests reach at m time
map<int, pair<int,int> > cnode_time;
// record consulates where the anti_clock guests reach at m time
map<int, pair<int,int> > anode_time;

int number[100001];
int queue[100001];
int clock_index[100001];
int anti_clock_index[100001];
int alocation[100001];
int clocation[100001];

int main()
{
    int a, i, n;
    int index;
    int node;
    int minu;
    int len;
    int location;
    char dir[8];

    cin >> a;
    for(int index=1; index<=a; index++){
        // initialize
        clockwise.clear();
        anti_clockwise.clear();
        cnode_time.clear();
        anode_time.clear();
        memset(clock_index, -1, sizeof(clock_index));
        memset(anti_clock_index, -1, sizeof(anti_clock_index));

        cin >> node >> n >> minu;
        for(int i=0; i<n; i++){
            cin >> location >> dir;
            // i-th guest in the clockwise or anti-clockwise set 
            if(dir[0]=='C'){
                clock_index[i]=location-1;
                clockwise[location-1]=true;
            }  
            else{
                anti_clock_index[i]=location-1;
                anti_clockwise[location-1]=true;
            }
        }

        // clockwise
        auto iter2=clockwise.begin();
        len=0;
        while(iter2!=clockwise.end()){
            queue[len]=iter2->first;
            ++len; 
            ++iter2;
        }
        if(minu>=node && clockwise.size()>0){               // O(node)  
            // when the number of clockwise guest is 1         
            if(clockwise.size()==1){
                int s, e, num=-1;
                auto iter1=clockwise.begin();
                s=iter1->first;
                e=(s+1)%node;
                while(s!=e){
                    // tagged by the s-th consulate 
                    cnode_time[s]={iter1->first, num--};
                    s=(s-1+node)%node;
                }
                cnode_time[s]={iter1->first,num};
            }
            else{
                //cosider the situation when each guest goes around
                int cur, pre, num;
                for(int i=0; i<len; i++){                   // O(node)
                    cur=queue[i];
                    pre=queue[(i-1+len)%len];
                    num=-1; 
                    while(cur!=pre){
                        cnode_time[cur]={queue[i], num--};
                        cur=(cur-1+node)%node;
                    }
                }
            }
        }

        for(int i=0; i<len; i++){
            int tminu1=minu;
            int tminu2=minu%node;
            int curr=i;
            int prev=(i-1+len)%len;
            int count = (queue[curr]-queue[prev]+node)%node;
            int start=(queue[curr]+tminu2)%node;
            // explain in detail in README
            if(count>tminu2||len==1){
                while(tminu2>=0){
                    auto temp=cnode_time.find(start);
                    if(temp==cnode_time.end()) cnode_time[start]={queue[i], tminu1};
                    else if(temp->second.second<tminu1) cnode_time[start]={queue[i], tminu1};
                    --tminu2;
                    --tminu1;
                    start=(start-1+node)%node;
                }
            }
            else{
                while(count--){
                    auto temp=cnode_time.find(start);
                    if(temp==cnode_time.end()) cnode_time[start]={queue[i], tminu1};
                    else if(temp->second.second<tminu1) cnode_time[start]={queue[i], tminu1};
                    --tminu1;
                    start=(start-1+node)%node;
                }
            }
        }

        // anti_clockwise
        iter2=anti_clockwise.begin();
        len=0;
        while(iter2!=anti_clockwise.end()){
            queue[len]=iter2->first;
            ++len;
            ++iter2;
        }
        if(minu>=node && anti_clockwise.size()>0){
            if(anti_clockwise.size()==1){
                int s, e, num=-1;
                auto iter1=anti_clockwise.begin();
                s=iter1->first;
                e=(s-1+node)%node;
                while(s!=e){
                    anode_time[s]={iter1->first,num--};
                    s=(s+1)%node;
                }
                anode_time[s]={iter1->first,num};
            }
            else{
                int cur, pre, num=-1;
                for(int i=0; i<len; i++){
                    cur=queue[i];
                    pre=queue[(i+1)%len];
                    num=-1;
                    while(cur!=pre){
                        anode_time[cur]={queue[i], num--};
                        cur=(cur+1)%node;
                    }
                }
            }
        }

        for(int i=0; i<len; i++){
            int tminu1=minu;
            int tminu2=minu%node;
            int curr=i;
            int prev=(i+1)%len;
            int count = (queue[prev]-queue[curr]+node)%node;
            int start=(queue[curr]-tminu2+node)%node;
            
            if(count>tminu2||len==1){
                while(tminu2>=0){
                    auto temp=anode_time.find(start);
                    if(temp==anode_time.end()) anode_time[start]={queue[i], tminu1};
                    else if(temp->second.second<tminu1) anode_time[start]={queue[i], tminu1};
                    --tminu2;
                    --tminu1;
                    start=(start+1)%node;
                }
            }
            else{
                while(count--){
                    auto temp=anode_time.find(start);
                    if(temp==anode_time.end()) anode_time[start]={queue[i], tminu1};
                    else if(temp->second.second<tminu1) anode_time[start]={queue[i], tminu1};
                    --tminu1;
                    start=(start+1)%node;
                }
            }
        }

        memset(number, 0, sizeof(number));
        memset(clocation, 0, sizeof(clocation));
        memset(alocation, 0, sizeof(alocation));
        while(cnode_time.size()>0){
            auto it1=cnode_time.begin();
            int tmp1=it1->first;
            int loc1=it1->second.first;
            int value1=it1->second.second;
            auto find=anode_time.find(tmp1);

            cnode_time.erase(tmp1);
            if(find==anode_time.end()){
                ++clocation[loc1];
                //for(auto it2=clock_index[loc1].begin(); it2!=clock_index[loc1].end(); ++it2) ++number[*it2];
            }
            else{
                int tmp2=find->first;
                int loc2=find->second.first;
                int value2=find->second.second;
                if(value2==value1){
                    ++clocation[loc1];
                    ++alocation[loc2];
                    //for(auto it2=clock_index[loc1].begin(); it2!=clock_index[loc1].end(); ++it2) ++number[*it2];
                    //for(auto it3=anti_clock_index[loc2].begin(); it3!=anti_clock_index[loc2].end(); ++it3) ++number[*it3];
                }
                else if(value2>value1){
                    ++alocation[loc2];
                    //for(auto it3=anti_clock_index[loc2].begin(); it3!=anti_clock_index[loc2].end(); ++it3) ++number[*it3];
                }
                else{
                    ++clocation[loc1];
                    //for(auto it2=clock_index[loc1].begin(); it2!=clock_index[loc1].end(); ++it2) ++number[*it2];
                }
                anode_time.erase(tmp2);
            }
        }

        while(anode_time.size()>0){
            auto it1=anode_time.begin();
            int tmp1=it1->first;
            int loc1=it1->second.first;
            int value1=it1->second.second;
            ++alocation[loc1];
            //for(auto it2=anti_clock_index[loc1].begin(); it2!=anti_clock_index[loc1].end(); ++it2) ++number[*it2];
            anode_time.erase(tmp1);
        }

        for(int i=0; i<n; i++){
            if(clock_index[i]>=0) number[i]+=clocation[clock_index[i]];
            else if(anti_clock_index[i]>=0) number[i]+=alocation[anti_clock_index[i]];
        }

        cout << "Case #" << index << ":";
        for(int i=0; i<n; i++) cout << " " << number[i];
        cout << endl;
    }
    return 0;
}

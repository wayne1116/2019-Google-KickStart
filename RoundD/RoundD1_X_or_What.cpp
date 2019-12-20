#include<iostream>
#include<map>
#include<vector>
using namespace std;

bool check_binary(int num)
{
    int count=0;
    while(num>0){
        count=count+(num&1);
        num>>=1;
    }
    return (count%2==1)?true:false;
}

int main()
{
    int a;
    int index;
    int in;
    int n, m;
    int number;
    map<int,int> oddindex;
    vector<int> result;

    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> n >> m;
        oddindex.clear();
        for(int i=0; i<n; i++){
            cin >> number;
            // check whether the number is xor-even. If not, put it in. 
            if(check_binary(number)) oddindex[i]=number;
        }

        result.clear();
        for(int i=0; i<m; i++){
            cin >> in >> number;
            // check whether the number is xor-even.
            bool flag=check_binary(number);
            // if the number is xor_even
            if(oddindex.find(in)!=oddindex.end()&&!flag) oddindex.erase(in);   
	    // if the number is not xor-even
            else if(oddindex.find(in)==oddindex.end()&&flag || oddindex.find(in)!=oddindex.end()) oddindex[in]=number;
			
	    // if the size of set is even             
            if(oddindex.size()%2==0) result.push_back(n);
            else{
                auto iterend=oddindex.end();
                auto iterbeg=oddindex.begin();
                --iterend;
                //  a1, a2, b1, ......, bm, ac, a(c+1); bi in the set for i=1,...,m
                result.push_back(max(iterend->first, n-iterbeg->first-1));
            }
        }

        cout << "Case #" << index << ":";
        for(int i=0; i<result.size(); i++) cout << " " << result[i];
        cout << endl;
    }
    return 0;
}

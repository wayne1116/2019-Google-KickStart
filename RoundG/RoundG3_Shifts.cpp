#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long result;
long long shift, happiness;
long long Ahappiness[32];
long long Bhappiness[32];
vector<pair<long long,long long> > vect1;
vector<pair<long long, long long> > vect2;
  
void solv1(int start, int end, long long Ahappy, long long Bhappy)
{
	  if(start==end){
		  vect1.push_back(pair<long long, long long>(Ahappy, Bhappy));
		  return;
	  }
	  solv1(start+1, end, Ahappy+Ahappiness[start], Bhappy);
	  solv1(start+1, end, Ahappy, Bhappy+Bhappiness[start]);
	  solv1(start+1, end, Ahappy+Ahappiness[start], Bhappy+Bhappiness[start]);
} 

void solv2(int start, int end, long long Ahappy, long long Bhappy)
{
	  if(start==end){
		  vect2.push_back(pair<long long, long long>(Ahappy, Bhappy));
		  return;
	  }
	  solv2(start+1, end, Ahappy+Ahappiness[start], Bhappy);
	  solv2(start+1, end, Ahappy, Bhappy+Bhappiness[start]);
	  solv2(start+1, end, Ahappy+Ahappiness[start], Bhappy+Bhappiness[start]);
}
 
bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	  if(a.first!=b.first) return b.first>a.first;
	  return b.second>a.second;
}
bool cmp1(const pair<long long, long long> &p1, const long long v)
{
	  if(p1.first<v) return true;
	  return false;
}
int main()
{
	  int a;
	  cin >> a;
	  for(int index=1; index<=a; index++){
		    cin >> shift >> happiness;
		    for(int i=0; i<shift; i++) cin >> Ahappiness[i];
		    for(int i=0; i<shift; i++) cin >> Bhappiness[i];
		    result=0;
		    vect1.clear();
		    vect2.clear();
		    solv1(0, shift/2, 0,0);
		    solv2(shift/2, shift, 0, 0);
		
		    sort(vect2.begin(), vect2.end(), cmp);
		
		    result=0;
		    for(auto p=vect1.begin(); p!=vect1.end(); p++){
			    auto temp = lower_bound(vect2.begin(), vect2.end(), happiness-p->first, cmp1);
			    for(auto q=temp; q!=vect2.end(); q++){
				      if(happiness-p->second<=q->second) ++result;
			    }
		    }
		    cout << "Case #" << index << ": " << result << endl;
	  }
	return 0;
}

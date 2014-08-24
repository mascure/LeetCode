#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<unordered_map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
const int MAX_N=100005;
typedef long long ll;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,vector<string> >group;
		for(auto s:strs){
			string key=s;
			sort(key.begin(),key.end());
			group[key].push_back(s);
		}
		vector<string> res;
		for(auto it:group){
			if(it.second.size()>1)
				res.insert(res.end(),it.second.begin(),it.second.end());
		}
		return res;
    }
};
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
}
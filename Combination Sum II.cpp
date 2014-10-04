#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
const int MAX_N=105;
const int inf=1000000;
const int MOD=1000000007;
typedef long long ll;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
		vector<vector<int> > res;
		vector<int> now;
		dfs(0,candidates,target,now,res);
		sort(res.begin(),res.end());
		res.erase(unique(res.begin(),res.end()),res.end());
		return res;
    }
private:
	void dfs(int start,vector<int> &candidates,int target,vector<int> &now,vector<vector<int> > &res){
		if(start==candidates.size()){
			if(target==0){
			res.push_back(now);
			}
			return;
		}
		dfs(start+1,candidates,target,now,res);
		if(candidates[start]<=target){
			now.push_back(candidates[start]);
			dfs(start+1,candidates,target-candidates[start],now,res);
			now.pop_back();
		}
	}
};
int main(){
	return 0;
}
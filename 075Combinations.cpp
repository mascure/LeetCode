#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<math.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_N 100005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105
typedef long long ll;
typedef unsigned long long ull;
using namespace std;



  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
class Solution {
public:
   vector<vector<int> > combine(int n, int k) {
	   vector<int> now;
	   vector<vector<int>> res;
       sou(0,0,k,n,now,res);
	   return res;
    }
private:
	void sou(int i,int level,int k,int n,vector<int> &now,vector<vector<int>> &res){
		if(level==k){
			res.push_back(now);
		}
		if(n-i<k-level)return;
		for(int j=i+1;j<=n;j++){
			now.push_back(j);
			sou(j,level+1,k,n,now,res);
			now.pop_back();
		}
	}
};
int main(){
	Solution S;
	vector<vector<int>> res=S.combine(10,7);
	int m=res.size(),n=res[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
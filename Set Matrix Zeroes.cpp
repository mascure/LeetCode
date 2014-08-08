#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<math.h>
#include<unordered_map>
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

typedef unsigned long long ull;
using namespace std;

  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
 typedef long long ll;
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size()==0||matrix[0].size()==0)return;
		int m=matrix.size(),n=matrix[0].size();
		vector<bool> r(m,false),c(n,false);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(matrix[i][j]==0){
					r[i]=true;
					c[j]=true;
				}
			}
		}
		for(int i=0;i<m;i++){
			if(r[i]){
				for(int j=0;j<n;j++)
					matrix[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			if(c[i]){
				for(int j=0;j<m;j++)
					matrix[j][i]=0;
			}
		}
    }
};
int main(){
	Solution S;
	vector<int> r(2,1);
	vector<vector<int> > matrix(1,r);
	cout<<S.searchMatrix(matrix,2)<<endl;
	return 0;
}
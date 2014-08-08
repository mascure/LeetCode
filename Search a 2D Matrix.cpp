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
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)return false;
		int m=matrix.size(),n=matrix[0].size();
		int L=0,H=m-1;
		while (L<=H)
		{
			int mid=L+((H-L)>>1);
			if(matrix[mid][0]<target){
				L=mid+1;
			}
			else if(matrix[mid][0]>target){
				H=mid-1;
			}
			else return true;
		}
		if(L==0)return false;
		vector<int>& row=matrix[L-1];
		L=0,H=n-1;
		while(L<=H){
			int mid=L+((H-L)>>1);
			if(row[mid]<target){
				L=mid+1;
			}
			else if(row[mid]>target){
				H=mid-1;
			}
			else return true;
		}
		return false;
    }
};
int main(){
	Solution S;
	vector<int> r(2,1);
	vector<vector<int> > matrix(1,r);
	cout<<S.searchMatrix(matrix,2)<<endl;
	return 0;
}
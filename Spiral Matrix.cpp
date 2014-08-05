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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
  typedef vector<int> BigInt;
class Solution {
public:
   vector<int> spiralOrder(vector<vector<int> > &matrix) {
       vector<int> res;
	   if(matrix.empty()) return res;
	   int up=0,bottom=matrix.size()-1;
	   int left=0,right=matrix[0].size()-1;
	   while(true){
		   for(int i=left;i<=right;i++)res.push_back(matrix[up][i]);
		   if(++up>bottom)break;
		   for(int i=up;i<=bottom;i++)res.push_back(matrix[i][right]);
		   if(--right<left)break;
		   for(int i=right;i>=left;i--)res.push_back(matrix[bottom][i]);
		   if(--bottom<up)break;
		   for(int i=bottom;i>=up;i--)res.push_back(matrix[i][left]);
		   if(++left>right)break;
	   }
	   return res;
   }
};
int main(){
	Solution S;
	vector<string> L;
	return 0;
}
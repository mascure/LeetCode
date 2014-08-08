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
#include<stack>
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
	int climbStairs(int n) {
		int p[2]={1,2},res=0;
		if(n<=2)return p[n-1];
		for(int i=3;i<=n;i++){
			res=p[0]+p[1];
			p[0]=p[1];
			p[1]=res;
		}
		return res;
    }
};
int main(){
	Solution S;
	return 0;
}
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
	int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
		if(m==0)return n;
		if(n==0)return m;
		vector<vector<int>> dp(m+1,vector<int>(n+1));
		for(int i=0;i<=n;i++)dp[0][i]=i;
		for(int i=0;i<=m;i++)dp[i][0]=i;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(word1[i]==word2[j])
					dp[i+1][j+1]=dp[i][j];
				else
					dp[i+1][j+1]=min(min(dp[i+1][j]+1,dp[i][j+1]+1),dp[i][j]+1);
			}
		}
		return dp[m][n];
    }
};
int main(){
	Solution S;
	return 0;
}
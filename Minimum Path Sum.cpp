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
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size()==0||grid[0].size()==0)return 0;
		int m=grid.size(),n=grid[0].size();
		vector<vector<int> > dp(m+1,vector<int>(n+1,0));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				const int M=std::numeric_limits<int>::max();
				int tmp=min(i==1?M:dp[i-1][j],j==1?M:dp[i][j-1]);
				dp[i][j]=grid[i-1][j-1];
				if(tmp!=M)
					dp[i][j]+=tmp;
			}
		}
		return dp[m][n];
    }
};
int main(){
	
	return 0;
}
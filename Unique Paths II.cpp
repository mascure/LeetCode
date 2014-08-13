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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0)return 0;
		int m=obstacleGrid.size(),n=obstacleGrid[0].size();
		if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1])return 0;
		vector<vector<int> > dp(m,vector<int>(n,0));
		dp[0][0]=1;
		for(int i=1;i<n;i++){
			dp[0][i]=dp[0][i-1];
			if(obstacleGrid[0][i])dp[0][i]=0;
		}
		for(int i=1;i<m;i++){
			dp[i][0]=dp[i-1][0];
			if(obstacleGrid[i][0])dp[i][0]=0;
		}
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
				if(obstacleGrid[i][j])dp[i][j]=0;
			}
		}
		return dp[m][n];
    }
};
int main(){
	
	return 0;
}
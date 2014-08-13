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
    int uniquePaths(int m, int n) {
		if(m==1||n==1)return 1;
		m--;n--;
        vector<vector<int> > C(m+n+1,vector<int>(m+n+1,0));
		for(int i=0;i<=m+n;i++){
			vector<int> tmp(m+n+1);
			tmp[0]=tmp[i]=1;;
			for(int j=1;j<i;j++){
				tmp[j]=C[i-1][j-1]+C[i-1][j];
			}
			C[i]=tmp;
		}
		return C[m+n][m];
    }
};
int main(){
	
	return 0;
}
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
#include<windows.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_SIZE 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
        vector<bool> col(n,false),dia1(2*n-1,false),dia2(2*n-1,false);
		int res=0;
		sou(0,col,dia1,dia2,n,res);
		return res;
    }
private:
	void sou(int row,vector<bool>& col,vector<bool>& dia1,vector<bool>& dia2,int n,int& res){
		if(row==n){
			res++;
			return;
		}
		for(int i=0;i<n;i++){
			if(!col[i]&&!dia1[row+i]&&!dia2[row+n-1-i]){
				col[i]=true;
				dia1[row+i]=true;
				dia2[row+n-1-i]=true;
				sou(row+1,col,dia1,dia2,n,res);
				dia2[row+n-1-i]=false;
				dia1[row+i]=false;
				col[i]=false;
			}
		}
	}
};
int main(){
	Solution S;
	return 0;
}
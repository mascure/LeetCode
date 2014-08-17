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
    vector<vector<string> > solveNQueens(int n) {
        vector<bool> col(n,false),dia1(2*n-1,false),dia2(2*n-1,false);
		vector<vector<string> >res;
		string s(n,'.');
		vector<string> now(n,s);
		sou(0,now,res,col,dia1,dia2,n);
		return res;
    }
private:
	void sou(int row,vector<string>& now,vector<vector<string> >&res,vector<bool>& col,vector<bool>& dia1,vector<bool>& dia2,int n){
		if(row==n){
			res.push_back(now);
			return;
		}
		for(int i=0;i<n;i++){
			if(!col[i]&&!dia1[row+i]&&!dia2[row+n-1-i]){
				col[i]=true;
				dia1[row+i]=true;
				dia2[row+n-1-i]=true;
				now[row][i]='Q';
				sou(row+1,now,res,col,dia1,dia2,n);
				now[row][i]='.';
				dia2[row+n-1-i]=false;
				dia1[row+i]=false;
				col[i]=false;
			}
		}
	}
};
int main(){
	Solution S;
	S.solveNQueens(8);
	return 0;
}
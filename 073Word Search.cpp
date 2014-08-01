#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<math.h>
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
class Solution {
public:
   bool exist(vector<vector<char> > &board, string word) {
		if(board.size()==0||board[0].size()==0)return false;
		if(word.length()==0)return false;
        int m=board.size(),n=board[0].size();
		vector<vector<bool>> visited(m,vector<bool>(n,0));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==word[0]){
					visited[i][j]=1;
					if(sou(i,j,0,word,visited,board))return true;
					visited[i][j]=0;
				}
			}
		}
		return false;
    }
private:
	bool sou(int x,int y,int i,string word,vector<vector<bool>>& visited,vector<vector<char> > &board){
		if(i+1==word.length())return true;
		int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
		int m=board.size(),n=board[0].size();
		for(int k=0;k<4;k++){
			int xx=x+dir[k][0],yy=y+dir[k][1];
			if(xx>=0&&xx<m&&yy>=0&&yy<n&&!visited[xx][yy]&&board[xx][yy]==word[i+1]){
				visited[xx][yy]=1;
				if(sou(xx,yy,i+1,word,visited,board))return true;
				visited[xx][yy]=0;
			}
		}
		return false;
	}
};
int main(){
	Solution S;
	return 0;
}
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
   string convert(string s, int nRows) {
	   if(s.length()==0||nRows==1)return s;
       vector<vector<char> > mat;
	   int len=s.length();
	   int width=(len-1)/(nRows*2-2)*(nRows-1);
	   int tmp=(len-1)%(nRows*2-2)+1;
	   if(tmp>nRows)width+=(tmp-nRows);
	   width++;
	   mat.resize(nRows,vector<char>(width,'\0'));
	   int i=0,r=-1,c=0;
	   while(i<len){
		   for(int j=0;j<nRows&&i<len;i++,j++){
			   mat[++r][c]=s[i];
		   }
		   for(int j=0;j<nRows-2&&i<len;i++,j++){
			   mat[--r][++c]=s[i];
		   }
		   r=-1;
		   c++;
	   }
	   string res="";
	   for(int i=0;i<nRows;i++){
		   for(int j=0;j<width;j++){
			   if(mat[i][j]!='\0')res+=mat[i][j];
		   }
	   }
	   return res;
   }
};
int main(){
	Solution S;
	S.convert("A",1);
	return 0;
}
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
	bool isNumber(const char *s) {
        int len=strlen(s);
		bool F=false,E=false;
		int start=0,end=len-1;
		while(start<len&&s[start]==' ')start++;
		if(start==len)return false;
		while(s[end]==' ')end--;
		for(int i=start;i<=end;i++){
			if(s[i]=='.'){
				if(F||E||(i==start&&i==end))return false;
				else F=true;
			}
			else if(isNum(s[i])||((i==start||i>start&&(s[i-1]=='E'||s[i-1]=='e'))&&(s[i]=='+'||s[i]=='-')&&(i<end&&isNum(s[i+1])||(i+1<end&&s[i+1]=='.'&&isNum(s[i+2])))))continue;
			else if(s[i]=='E'||s[i]=='e'){
				if(E||i==start||i==end||!(isNum(s[i-1])||(i>start+1&&s[i-1]=='.'&&isNum(s[i-2]))))return false;
				else
				E=true;
			}
			else
				return false;
		}
		return true;
    }
private:
	bool isNum(char c){
		if(c>='0'&&c<='9')return true;
		else return false;
	}
};
int main(){
	Solution S;
	return 0;
}
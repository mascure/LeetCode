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
	string simplifyPath(string path) {
        vector<string> s;
		path=elimateSlashes(path);
		if(path[path.length()-1]=='/')path=path.substr(0,path.length()-1);
		int i=0;
		while(i<path.length()){
			int next=path.find_first_of('/',i+1);
			next=next==-1?path.length():next;
			string dir=path.substr(i+1,next-i-1);
			i=next;
			if(dir==".."){
				if(!s.empty())s.pop_back();
			}
			else if(dir==".")continue;
			else
				s.push_back(dir);
		}
		string res="";
		for(i=0;i<s.size();i++){
			res+="/"+s[i];
		}
		if(res=="")res="/";
		return res;
    }
private:
	string elimateSlashes(string str){
		int t=0;
		for(int i=0;i<str.length();i++){
			str[t++]=str[i];
			if(str[i]=='/'){
				while(i<str.length()&&str[i]=='/')i++;
				i--;
			}
		}
		return str.substr(0,t);
	}
};
int main(){
	Solution S;
	cout<<S.simplifyPath("/a/./b/../../c/")<<endl;
	return 0;
}
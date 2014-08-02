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
   string minWindow(string S, string T) {
        if(T.length()>S.length()||S.empty())return "";
		const int ASCII_MAX=256;
		int appear[ASCII_MAX];
		int expect[ASCII_MAX];
		fill(appear,appear+ASCII_MAX,0);
		fill(expect,expect+ASCII_MAX,0);
		for(int i=0;i<T.length();i++)expect[T[i]]++;
		int minWidth=INT_MAX,min_start=0;
		int wnd_start=0;
		int appeared=0;
		for(int end=0;end<S.length();end++){
			if(expect[S[end]]>0){
				appear[S[end]]++;
				if(appear[S[end]]<=expect[S[end]]){
					appeared++;
				}
			}
			if(appeared==T.length()){
				while(expect[S[wnd_start]]==0||appear[S[wnd_start]]>expect[S[wnd_start]]){
					appear[S[wnd_start]]--;
					wnd_start++;
				}
				if(minWidth>end-wnd_start){
					min_start=wnd_start;
					minWidth=end-wnd_start+1;
				}
			}
		}
		if(minWidth==INT_MAX)return "";
		else
			return S.substr(min_start,minWidth);
    }
};
int main(){
	Solution S;
	cout<<numeric_limits<int>::max()<<endl;
	return 0;
}
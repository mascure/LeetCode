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
	string addBinary(string a, string b) {
        string res;
		int c=0;
		int L1=a.length(),L2=b.length();
		for(int i=0;i<L1||i<L2;i++){
			int n1=i<L1?a[L1-1-i]-'0':0;
			int n2=i<L2?b[L2-1-i]-'0':0;
			int n=c+n1+n2;
			if(n>1)c=1;
			else c=0;
			n=n%2;
			char c=('0'+n);
			res=c+res;
		}
		if(c)res='1'+res;
		return res;
    }
};
int main(){
	Solution S;
	return 0;
}
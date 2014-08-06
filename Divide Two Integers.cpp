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
	int divide(int dividend, int divisor) {
		ll res=0;
		bool flag=1;
		ll Dividend=dividend,Divisor=divisor;
		if(dividend<0){
			Dividend=-Dividend;
			flag=!flag;
		}
		if(divisor<0){
			Divisor=-Divisor;
			flag=!flag;
		}
		ll tmp=Divisor,t=1;
		while(tmp<=Dividend){
			tmp<<=1;
			t<<=1;
		}
		t>>=1;
		tmp>>=1;
		while(t>0){
			if(Dividend>=tmp){
				res+=t;
				Dividend-=tmp;
			}
			tmp>>=1;
			t>>=1;
		}
		if(!flag)res=-res;
		return res;
	}
};
int main(){
	Solution S;
	cout<<S.divide(-1,1)<<endl;
	return 0;
}
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
   string multiply(string num1, string num2) {
	   BigInt res=mult(make(num1),make(num2));
	   return toString(res);
   }
private:
	BigInt make(string s){
		BigInt n(s.length());
		for(int i=s.length()-1;i>=0;i--){
			n[s.length()-1-i]=s[i]-'0';
		}
		return n;
	}
	BigInt mult(BigInt num1,BigInt num2){
		int n1=num1.size(),n2=num2.size();
		int n=n1+n2;
		BigInt res(n,0);
		for(int i=0;i<n1;i++){
			for(int j=0;j<n2;j++){
				int c=num1[i]*num2[j];
				int t=res[i+j]+c%10;
				res[i+j]=t%10;
				res[i+j+1]+=c/10+t/10;
			}
		}
		vector<int>::iterator it=res.end();
		for(it=res.end()-1;it!=res.begin();it--){
			if((*it)!=0){
				break;
			}
		}
		res.erase(it+1,res.end());
		return res;
	}
	string toString(BigInt num){
		string res(num.size(),'0');
		for(int i=0;i<num.size();i++){
			res[num.size()-1-i]=num[i]+'0';
		}
		return res;
	}
};
int main(){
	Solution S;
	cout<<S.multiply("123","456")<<endl;
	return 0;
}
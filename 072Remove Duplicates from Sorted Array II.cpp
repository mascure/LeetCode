#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<list>
#include <stack>
#include<queue>
#include<sstream>
#include<map>
//#include<unordered_set>
#include<unordered_map>
//#include<time.h>
#define MAX_E 1000000
#define MAX_V 100005
#define MAX_N 100005
#define MAX_M 105;
typedef long long ll;
using namespace std;
int const MOD=1000000007;
int const inf=0x7fffffff;
   struct ListNode {
       int val;
       ListNode  *next;
       ListNode(int x) : val(x), next(NULL) {}
   };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int s=0,res=n;
		for(int i=0;i<n;i++,s++){
			A[s]=A[i];
			if(i+2<n&&A[i]==A[i+1]&&A[i+1]==A[i+2]){
				A[++s]=A[++i];
				while(i+1<n&&A[i]==A[i+1]){
					res--;
					i++;
				}
				if(i+1<n){
					A[s+1]=A[i+1];
				}
			}
		}
		return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    int A[]={1,3,5};
    clock_t start=clock();
    clock_t end=clock();
    cout<<end-start<<endl;
    end=clock();
    cout<<end-start<<endl;
    return 0;
}

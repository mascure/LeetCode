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
//#include<unordered_map>
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
    int numTrees(int n) {
        vector<int> f(n+1);
        f[0]=f[1]=1;
        for (int i=2; i<=n; i++) {
            f[i]=0;
            for (int j=0; j<i; j++) {
                f[i]+=f[j]*f[i-1-j];
            }
        }
        return f[n];
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    cout<<S.isInterleave("aacaac", "aacaaeaac","aacaaeaaeaacaac")<<endl;
    return 0;
}

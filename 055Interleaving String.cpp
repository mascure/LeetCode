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
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if (n1+n2!=n3) {
            return false;
        }
        vector<vector<int>> f(n3+1,vector<int>(n1+1,0));
        f[0][0]=1;
        for (int i=0; i<n3; i++) {
            for (int j=0; j<=n1&&j<=i; j++) {
                if (!f[i][j]) {
                    continue;
                }
                int k=i-j;
                if (k<n2&&s2[k]==s3[i]) {
                    f[i+1][j]=1;
                }
                if (j<n1&&s1[j]==s3[i]) {
                    f[i+1][j+1]=1;
                }
            }
        }
        return f[n3][n1];
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    cout<<S.isInterleave("aacaac", "aacaaeaac","aacaaeaaeaacaac")<<endl;
    return 0;
}

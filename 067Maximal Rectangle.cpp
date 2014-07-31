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
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size()==0||matrix[0].size()==0) {
            return 0;
        }
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> H(m,vector<int>(n,0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j]=='1') {
                    if (i==0) {
                        H[i][j]=1;
                    }
                    else
                    H[i][j]=H[i-1][j]+1;
                }
            }
        }
        int res=0;
        for (int i=0; i<m; i++) {
            vector<int> L(n,0),R(n,0),st(n,0);
            int t=0;
            vector<int>& h=H[i];
            for (int j=0; j<n; j++) {
                while (t>0&&h[st[t-1]]>=h[j]) {
                    t--;
                }
                L[j]=(t==0?0:st[t-1]+1);
                st[t++]=j;
            }
            t=0;
            for (int j=n-1; j>=0; j--) {
                while (t>0&&h[st[t-1]]>=h[j]) {
                    t--;
                }
                R[j]=(t==0?n:st[t-1]);
                st[t++]=j;
            }
            for (int j=0; j<n; j++) {
                res=max(res, h[j]*(R[j]-L[j]));
            }
        }
        return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    clock_t start=clock();
    clock_t end=clock();
    cout<<end-start<<endl;
    end=clock();
    cout<<end-start<<endl;
    return 0;
}

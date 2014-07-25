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
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 100005
#define MAX_N 100005
#define MAX_M 105;
typedef long long ll;
using namespace std;
int const MOD=1000000007;

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p==NULL&&q==NULL) {
            return true;
        }
        if ((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)) {
            return false;
        }
        if (p->val!=q->val) {
            return false;
        }
        int res1=isSameTree(p->left, q->left);
        int res2=isSameTree(p->right, q->right);
        return res1&res2;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

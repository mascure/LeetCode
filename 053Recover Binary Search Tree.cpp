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
//参考discuss
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (root==NULL) {
            return;
        }
        TreeNode p(numeric_limits<int>::min());
        TreeNode *a=NULL,*b=NULL,*pre=&p;
        recover(root, pre, a, b);
        if (a&&b) {
            swap(a->val, b->val);
        }
    }
private:
    void recover(TreeNode *root,TreeNode *&pre,TreeNode *&a,TreeNode *&b){
        if (root==NULL) {
            return;
        }
        recover(root->left, pre, a, b);
        if (root->val<pre->val) {
            if (a==NULL) {
                a=pre;
            }
            b=root;
        }
        pre=root;
        recover(root->right, pre, a, b);
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

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
//#include<ext/hash_map>
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
//本代码采用递归解法
//迭代解法思路：一层一层处理，每个节点保存位置，对每一层，若所有节点的值和位置是是回文，则本层为true，继续处理下一层，否则返回false
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root==NULL) {
            return true;
        }
        return symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode *root1,TreeNode *root2){
        if (root1==NULL&&root2==NULL) {
            return true;
        }
        if (!(root1!=NULL&&root2!=NULL)) {
            return false;
        }
        if (root1->val!=root2->val) {
            return false;
        }
        int res1=symmetric(root1->left, root2->right);
        int res2=symmetric(root1->right, root2->left);
        return res1&res2;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

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
    bool isValidBST(TreeNode *root) {
        return valid(root, 0x80000000, 0x7fffffff);
    }
private:
    bool valid(TreeNode *root,int low,int high){
        if (root==NULL) {
            return true;
        }
        if (root->val<=low||root->val>=high) {
            return false;
        }
        bool res1=valid(root->left, low, root->val);
        bool res2=valid(root->right, root->val, high);
        return res1&res2;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

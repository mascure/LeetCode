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
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size()!=preorder.size()) {
            return NULL;
        }
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode *build(vector<int> &preorder, int pstart,int pend,vector<int> &inorder,int istart,int iend){
        if (pstart==pend) {
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[pstart]);
        int p=istart;
        while (p<iend&&inorder[p]!=preorder[pstart]) {
            p++;
        }
        root->left=build(preorder, pstart+1, pstart+1+p-istart, inorder, istart, p);
        root->right=build(preorder, pstart+1+p-istart, pend, inorder, p+1, iend);
        return root;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

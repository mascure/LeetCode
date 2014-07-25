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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size()!=postorder.size()) {
            return NULL;
        }
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode *build(vector<int> &inorder, int istart,int iend,vector<int> &postorder,int pstart,int pend){
        if (pstart==pend) {
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[pend-1]);
        int p=iend-1;
        while (p>=istart&&inorder[p]!=postorder[pend-1]) {
            p--;
        }
        root->left=build(inorder, istart, p, postorder, pstart, pstart+p-istart);
        root->right=build(inorder, p+1, iend, postorder, pstart+p-istart, pend-1);
        return root;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

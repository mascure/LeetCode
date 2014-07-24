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
struct TreeNode {
      int val;
      TreeNode *left, *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root==NULL) {
            return false;
        }
        if (root->left==NULL&&root->right==NULL) {
            return root->val==sum;
        }
        else{
            int r1=0,r2=0;
            if (root->left!=NULL) {
                r1=hasPathSum(root->left, sum-root->val);
            }
            if (!r1&&root->right!=NULL) {
                r2=hasPathSum(root->right, sum-root->val);
            }
            return r1|r2;
        }
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    TreeNode node1(1),node2(2),node3(3);
    node1.left=&node2;
    node2.left=&node3;
    S.flatten(&node1);
    TreeNode *p=&node1;
    while (p!=NULL) {
        cout<<p->val<<endl;
        p=p->right;
    }
    return 0;
}

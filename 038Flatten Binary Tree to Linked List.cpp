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
    void flatten(TreeNode *root) {
        if (root==NULL) {
            return;
        }
        flat(root);
    }
private:
    TreeNode* flat(TreeNode* root){
        //p是先序遍历的最后一个节点
        TreeNode* p;
        if (root->left!=NULL) {
            p=flat(root->left);
            p->right=root->right;
            root->right=root->left;
            root->left=NULL;
            if (p->right!=NULL) {
                return flat(p->right);
            }
            else
                return p;
        }
        else{
            if (root->right==NULL) {
                return root;
            }
            else{
                return flat(root->right);
            }
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

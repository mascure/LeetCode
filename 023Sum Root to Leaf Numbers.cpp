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
#include<unordered_set>
#include<unordered_map>
#include<ext/hash_map>
#include<time.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 500
#define MAX_N 105
#define MAX_M 20;
typedef long long ll;
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int res=0;
        if (root!=nullptr) {
            compute(root, 0, res);
        }
        return res;
    }
private:
    void compute(TreeNode *root,int path,int& total){
        path=path*10+root->val;
        //叶节点
        if (root->left==nullptr&&root->right==nullptr) {
            total+=path;
            return;
        }
        if (root->left!=nullptr) {
            compute(root->left, path, total);
        }
        if (root->right!=nullptr) {
            compute(root->right, path, total);
        }
    }
};


int main() {
    Solution S;
    clock_t start=clock();
    clock_t end=clock();
    cout<<end-start<<endl;
    return 0;
}

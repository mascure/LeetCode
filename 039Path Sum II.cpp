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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if (root==NULL) {
            return res;
        }
        vector<int> path;
        getPath(root, sum, path, res);
        return res;
    }
private:
    void getPath(TreeNode *root,int sum,vector<int> &path,vector<vector<int>> &res){
        path.push_back(root->val);
        if (root->left==NULL&&root->right==NULL) {
            if (root->val==sum) {
                res.push_back(path);
            }
        }
        else{
            if (root->left!=NULL) {
                getPath(root->left, sum-root->val, path, res);
            }
            if (root->right!=NULL) {
                getPath(root->right, sum-root->val, path, res);
            }
        }
        path.pop_back();
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    
    return 0;
}

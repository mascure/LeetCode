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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> s;
        TreeNode *pre=nullptr;
        s.push(root);
        while (!s.empty()) {
            auto it=s.top();
            s.pop();
            if (!it->left||(it->left&&check(pre, it->left))) {
                res.push_back(it->val);
                pre=it;
                if (!it->left&&it->right) {
                    s.push(it->right);
                }
                continue;
            }
            if (it->right) {
                s.push(it->right);
            }
            s.push(it);
            s.push(it->left);
        }
        return res;
    }
private:
    bool check(TreeNode *pre,TreeNode *root){
        TreeNode *p=root;
        while (p->right) {
            p=p->right;
        }
        return pre==p;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    cout<<S.isInterleave("aacaac", "aacaaeaac","aacaaeaaeaacaac")<<endl;
    return 0;
}

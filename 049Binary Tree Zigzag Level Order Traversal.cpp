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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root==NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int L=1;
        while (!q.empty()) {
            queue<TreeNode*> nextLevel;
            vector<int> tmp;
            while (!q.empty()) {
                TreeNode *top=q.front();
                tmp.push_back(top->val);
                if (top->left!=NULL) {
                    nextLevel.push(top->left);
                }
                if (top->right!=NULL) {
                    nextLevel.push(top->right);
                }
                q.pop();
            }
            if (L%2==0) {
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);
            L++;
            swap(q, nextLevel);
        }
        return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

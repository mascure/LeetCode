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
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
private:
    vector<TreeNode *> generate(int start,int end){
        vector<TreeNode *> res;
        if (start>end) {
            res.push_back(NULL);
            return res;
        }
        for (int i=start; i<=end; i++) {
            vector<TreeNode *> left=generate(start,i-1);
            vector<TreeNode *> right=generate(i+1,end);
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    TreeNode *root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    cout<<S.isInterleave("aacaac", "aacaaeaac","aacaaeaaeaacaac")<<endl;
    return 0;
}

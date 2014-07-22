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
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if(root==NULL)return 0;
        int res=root->val;
        compute(root,res);
        return res;
    }
private:
    int compute(TreeNode *root,int& res){
        int left=0,right=0;
        if(root->left!=NULL)
            left=compute(root->left,res);
        if(root->right!=NULL)
            right=compute(root->right,res);
        left=left<0?0:left;
        right=right<0?0:right;
        res=max(res,left+root->val+right);
        return root->val+max(left,right);
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    return 0;
}

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
    int minDepth(TreeNode *root) {
        if (root==NULL) {
            return 0;
        }
        int d1=minDepth(root->left),d2=minDepth(root->right);
        if (d1==0||d2==0) {
            return (d1==0?d2:d1)+1;
        }
        else
        return min(d1, d2)+1;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    
    return 0;
}

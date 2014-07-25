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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBST(num, 0, num.size());
    }
private:
    TreeNode *toBST(vector<int> &num,int start,int end){
        if (start==end) {
            return NULL;
        }
        if (start+1==end) {
            return new TreeNode(num[start]);
        }
        int mid=start+(end-start)/2;
        TreeNode *root=new TreeNode(num[mid]);
        root->left=toBST(num, start, mid);
        root->right=toBST(num, mid+1, end);
        return root;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head==nullptr) {
            return NULL;
        }
        if (head->next==NULL) {
            return new TreeNode(head->val);
        }
        ListNode *step1=head,*step2=head->next;
        while (step2->next!=NULL&&step2->next->next!=NULL) {
            step1=step1->next;
            step2=step2->next->next;
        }
        //以step1的下一个为根
        TreeNode* root=new TreeNode(step1->next->val);
        ListNode *head2=step1->next->next;
        delete step1->next;
        step1->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(head2);
        return root;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    
    return 0;
}

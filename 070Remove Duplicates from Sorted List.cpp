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
#include<unordered_map>
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==nullptr||head->next==nullptr) {
            return head;
        }
        ListNode *p=head;
        while (p->next!=nullptr) {
            ListNode *tmp=p->next;
            if (p->val==tmp->val) {
                p->next=tmp->next;
                delete tmp;
            }
            else
                p=p->next;
        }
        return head;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    clock_t start=clock();
    clock_t end=clock();
    cout<<end-start<<endl;
    end=clock();
    cout<<end-start<<endl;
    return 0;
}

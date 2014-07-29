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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m==n) {
            return head;
        }
        int mid=m+((n-m)>>1);
        int i=1;
        ListNode *p=head;
        while (i<m) {
            p=p->next;
            i++;
        }
        stack<ListNode *> s;
        while (i<=mid) {
            s.push(p);
            i++;
            p=p->next;
        }
        if ((n-m)%2==0) {
            s.pop();
        }
        while (i<=n) {
            auto top=s.top();
            swap(top->val, p->val);
            p=p->next;
            s.pop();
            i++;
        }
        return head;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    ListNode *head=new ListNode(1);
    ListNode *node1=new ListNode(2);
    ListNode *node2=new ListNode(3);
    head->next=node1;
    node1->next=node2;
    ListNode *res=S.reverseBetween(head, 1, 3);
    while (res!=nullptr) {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;
}

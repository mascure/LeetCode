#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<math.h>
#include<unordered_map>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_N 100005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(head==nullptr||head->next==nullptr)return head;
        int len=0;
		ListNode *p=head;
		while(p!=nullptr){
			len++;
			p=p->next;
		}
		k=k%len;
		if(k==0)return head;
		int t=len-k-1;
		p=head;
		while(t>0){
			p=p->next;
			t--;
		}
		ListNode *newHead=p->next,*pp=p->next;
		p->next=nullptr;
		while(pp->next!=nullptr){
			pp=pp->next;
		}
		pp->next=head;
		return newHead;
    }
};
int main(){
	
	return 0;
}
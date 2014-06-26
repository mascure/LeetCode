#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<math.h>
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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		//元素数为0或1，直接返回
		if(head==NULL||head->next==NULL)return head;
        ListNode *resHead=head,*p=head->next;
		resHead->next=NULL;
		while(p!=NULL){
			ListNode *t=resHead,*last=NULL;
			while(t!=NULL&&p->val>t->val){
				last=t;
				t=t->next;
			}
			if(last!=NULL){
			last->next=p;
			p=p->next;
			last->next->next=t;
			}
			//插入头部
			else{
				ListNode* newHead=p;
				p=p->next;
				newHead->next=resHead;
				resHead=newHead;
			}
		}
		return resHead;
    }
};
int main(){
	ListNode *p=new ListNode(1);
	ListNode *head=p;
	p->next=new ListNode(1);
	p=p->next;
	//p->next=new ListNode(4);
	Solution S;
	ListNode *res=S.insertionSortList(head);
	while(res!=NULL){
		cout<<res->val<<" ";
		res=res->next;
	}
	return 0;
}
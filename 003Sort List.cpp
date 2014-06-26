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
	ListNode* merge_sort(ListNode *head){
		//切分为两段
		int num=0;
		ListNode* p=head;
		while(p!=NULL){
			p=p->next;
			num++;
		}
		if(num<2)return head;
		int Mid=0;
		p=head;
		ListNode* last=head;
		while(Mid<num/2){
			last=p;
			p=p->next;
			Mid++;
		}
		last->next=NULL;
		head=merge_sort(head);
		p=merge_sort(p);
		//两个链表每个长度至少为1
		ListNode *Left=head,*Right=p,*resHead=new ListNode(0),*resTail=resHead;
		last=NULL;
		while(Left!=NULL&&Right!=NULL){
			if(Left->val<Right->val){
				resTail->val=Left->val;
				Left=Left->next;
			}
			else{
				resTail->val=Right->val;
				Right=Right->next;
			}
			resTail->next=new ListNode(0);
			last=resTail;
			resTail=resTail->next;
		}
		while(Left!=NULL){
			resTail->val=Left->val;
			Left=Left->next;
			resTail->next=new ListNode(0);
			last=resTail;
			resTail=resTail->next;
		}
		while(Right!=NULL){
			resTail->val=Right->val;
			Right=Right->next;
			resTail->next=new ListNode(0);
			last=resTail;
			resTail=resTail->next;
		}
		delete resTail;
		last->next=NULL;
		//释放左半部分
		while(head!=NULL){
			ListNode *tmp=head;
			head=head->next;
			delete tmp;
		}
		//释放有半部分
		while(p!=NULL){
			ListNode *tmp=p;
			p=p->next;
			delete tmp;
		}
		return resHead;
	}
    ListNode *sortList(ListNode *head) {
        return merge_sort(head);
    }
};
int main(){
	return 0;
}
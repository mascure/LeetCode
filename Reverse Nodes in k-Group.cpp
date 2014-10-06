#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *last=NULL,*front=head,*p=head;
		while(front){
			int t=0;
			while(front&&t<k){
				front=front->next;
				t++;
			}
			if(t<k){
				if(last)
				last->next=p;
				continue;
			}
			ListNode *pre=NULL,*first=p;
			while(p!=front){
				ListNode *tmp=p->next;
				p->next=pre;
				pre=p;p=tmp;
			}
			if(last){
				last->next=pre;
				last=first;
			}
			else{
				head=pre;
				last=first;
			}
		}
		return head;
    }
};
int main() {
    return 0;
}
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *last=NULL,*p=head;
		while(p){
			if(p->next){
				ListNode *tmp=p->next->next;
				if(last){
					last->next=p->next;
				}
				else{
					head=p->next;
				}
				p->next->next=p;
				p->next=NULL;
				last=p;
				p=tmp;
			}
			else{
				if(last)last->next=p;
				break;
			}
		}
		return head;
    }
};
int main() {
    return 0;
}
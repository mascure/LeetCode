#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *front=head,*p=head,*pre=NULL;
		while(n--){
			front=front->next;
		}
		while(front){
			pre=p;
			p=p->next;
			front=front->next;
		}
		if(pre){
			pre->next=p->next;
		}
		else{
			head=p->next;
		}
		delete p;
		return head;
    }
};
int main() {
    return 0;
}
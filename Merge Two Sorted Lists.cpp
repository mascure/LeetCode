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
 
 typedef long long ll;
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==nullptr)return l2;
		if(l2==nullptr)return l1;
		ListNode *head=nullptr,*p1=l1,*p2=l2,*last=nullptr;
		while(p1!=nullptr&&p2!=nullptr){
			if(p1->val<p2->val){
				if(head==nullptr){
					head=p1;
					last=p1;
				}
				else{
					last->next=p1;
					last=p1;
				}
				p1=p1->next;
			}
			else{
				if(head==nullptr){
					head=p2;
					last=p2;
				}
				else{
					last->next=p2;
					last=p2;
				}
				p2=p2->next;
			}
		}
		if(p1==nullptr)last->next=p2;
		if(p2==nullptr)last->next=p1;
		return head;
    }
};
int main(){
	Solution S;
	return 0;
}
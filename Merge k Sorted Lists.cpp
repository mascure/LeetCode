#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public: 
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head=NULL,*p=NULL;
		priority_queue<ListNode*,vector<ListNode*>,cmp> S;
		for(int i=0;i<lists.size();i++){
			if(lists[i])S.push(lists[i]);
		}
		while(S.size()){
			ListNode* t=S.top();S.pop();
			if(p){
				p->next=t;
			}
			else{
				head=p=t;
			}
			p=t;
			if(p->next){S.push(p->next);}
		}
		return head;
    }
private:
	vector<ListNode *> List;
	struct cmp{
		bool operator() ( ListNode* a, ListNode* b ){
			return a->val>b->val;
		}
	};
};
int main() {
    return 0;
}
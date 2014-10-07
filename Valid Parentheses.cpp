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
    bool isValid(string s) {
        stack<char> S;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('||s[i]=='['||s[i]=='{'){
				S.push(s[i]);
			}
			else{
				if(s[i]==')'){
					if(S.size()&&S.top()=='(')S.pop();
					else return false;
				}
				else if(s[i]==']'){
					if(S.size()&&S.top()=='[')S.pop();
					else return false;
				}
				else{
					if(S.size()&&S.top()=='{')S.pop();
					else return false;
				}
			}
		}
		return S.empty();
    }
};
int main() {
    return 0;
}
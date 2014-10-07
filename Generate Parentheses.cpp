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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
		int num=0;
		string str="";
		generate(n,num,str,res);
		return res;
    }
private:
	void generate(int n,int num,string &str,vector<string> &res){
		if(n==0&&num==0){
			res.push_back(str);
			return;
		}
		if(n>0){
			str+='(';
			generate(n-1,num+1,str,res);
			str.pop_back();
		}
		if(num){
			str+=')';
			generate(n,num-1,str,res);
			str.pop_back();
		}
	}
};
int main() {
    return 0;
}
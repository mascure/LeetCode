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
    vector<string> letterCombinations(string digits) {
        vector<string> m(10);
		m[0]=" ";
		m[1]="";
		m[2]="abc";
		m[3]="def";
		m[4]="ghi";
		m[5]="jkl";
		m[6]="mno";
		m[7]="pqrs";
		m[8]="tuv";
		m[9]="wxyz";
		vector<string> res;
		string now="";
		generate(digits,m,now,res);
		return res;
    }
private:
	void generate(string digits,vector<string> &m,string &now,vector<string> &res){
		if(digits.length()==0){
			res.push_back(now);
			return;
		}
		int t=digits[0]-'0';
		for(int i=0;i<m[t].length();i++){
			now+=m[t][i];
			generate(digits.substr(1),m,now,res);
			now.pop_back();
		}
	}
};
int main() {
    return 0;
}
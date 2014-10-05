#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
		vector<int> pre(s.length(),0);
		stack<int> S;
		int ans=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('){
				S.push(1);
			}
			else{
				if(S.size()){
					if(s[i-1]=='('){
						pre[i]=(i-2>=0?pre[i-2]:0)+2;
					}
					else{
						pre[i]=pre[i-1]+2;
						if(i>=pre[i])pre[i]+=pre[i-pre[i]];
					}
					S.pop();
				}
			}
			ans=max(ans,pre[i]);
		}
		return ans;
    }
};
int main() {
	Solution S;
	string s;
	while(cin>>s)
	cout<<S.longestValidParentheses(s)<<endl;
    return 0;
}
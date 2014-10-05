#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i=num.size()-1;
		while(i>0&&num[i-1]>=num[i])i--;
		if(i==0){
			reverse(num.begin(),num.end());
		}
		else{
			i--;
			int j=num.size()-1;
			while(num[j]<=num[i])j--;
			swap(num[i],num[j]);
			auto iter=num.begin();
			advance(iter,i+1);
			sort(iter,num.end());
		}
    }
};
int main() {
	Solution S;
	string s;
    return 0;
}
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

  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
 typedef long long ll;
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
        int len=digits.size()-1;
		while(len>=0){
			digits[len]++;
			if(digits[len]<=9){
				break;
			}
			else
				digits[len]=0;
			len--;
		}
		if(len==-1){
			digits.push_back(1);
			rotate(digits.begin(),digits.begin()+digits.size()-1,digits.end());
		}
		return digits;
    }
};
int main(){
	Solution S;
	vector<int> digit(1,0);
	S.plusOne(digit);
	return 0;
}
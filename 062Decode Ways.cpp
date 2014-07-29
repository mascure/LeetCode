#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<list>
#include <stack>
#include<queue>
#include<sstream>
#include<map>
//#include<unordered_set>
//#include<unordered_map>
//#include<time.h>
#define MAX_E 1000000
#define MAX_V 100005
#define MAX_N 100005
#define MAX_M 105;
typedef long long ll;
using namespace std;
int const MOD=1000000007;
int const inf=0x7fffffff;
   struct ListNode {
       int val;
       ListNode  *next;
       ListNode(int x) : val(x), next(NULL) {}
   };

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int numDecodings(string s) {
        int res=0;
        int pre1=0,pre2=1,n=s.length();
        if(s[0]=='0')return 0;
        for (int i=0; i<n; i++) {
            if(i>0&&s[i]=='0'&&s[i-1]=='0')return 0;
            if (s[i]=='0') {
                if (std::stoi(s.substr(i-1,2))>26) {
                    return 0;
                }
                res=pre1;
            }
            else{
                res=pre2;
                if (i>0&&s[i-1]!='0'&&std::stoi(s.substr(i-1,2))<=26) {
                    res+=pre1;
                }
            }
            pre1=pre2;
            pre2=res;
        }
        
        return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    clock_t start=clock();
    cout<<S.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948")<<endl;
    clock_t end=clock();
    cout<<end-start<<endl;
    end=clock();
    cout<<end-start<<endl;
    return 0;
}

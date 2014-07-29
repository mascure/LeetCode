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
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length()<4||s.length()>12) {
            return res;
        }
        string now;
        restore(s, 3, res, now);
        return res;
    }
private:
    void restore(string s,int level,vector<string> &res,string &now){
        if (level<0) {
            res.push_back(now.substr(0,now.length()-1));
            return;
        }
        int n=s.length();
        int start=max(1,n-3*level);
        int cn=min(n-level,3);
        for (int i=start; i<=cn; i++) {
            string tmp=s.substr(0,i);
            int num=std::stoi(tmp);
            if (num>255||(tmp[0]=='0'&&num!=0)||(num==0&&tmp!="0")) {
                continue;
            }
            now=now+s.substr(0,i)+".";
            restore(s.substr(i), level-1, res, now);
            now=now.substr(0,now.length()-i-1);
        }
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    vector<string> res=S.restoreIpAddresses("010010");
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}

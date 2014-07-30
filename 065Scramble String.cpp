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
#include<unordered_map>
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
    bool isScramble(string s1, string s2) {
        if (s1.length()!=s2.length()) {
            return false;
        }
        if (s1==s2) {
            return true;
        }
        int n=s1.size();
        for (int i=1; i<n; i++) {
            string s11=s1.substr(0,i);
            string s12=s1.substr(i);
            string s21=s2.substr(0,i);
            string s22=s2.substr(i);
            string s23=s2.substr(0,n-i);
            string s24=s2.substr(n-i);
            if ((check(s11,s21)&&isScramble(s11, s21)&&check(s12,s22)&&isScramble(s12, s22))
                ||(check(s11, s24)&&isScramble(s11, s24)&&check(s12, s23)&&isScramble(s12, s23))) {
                return true;
            }
        }
        return false;
    }
private:
    bool check(string s1,string s2){
        unordered_map<char,int> m;
        int n=s1.length();
        for (int i=0; i<n; i++) {
            if (m.count(s1[i])==0) {
                m[s1[i]]=1;
            }
            else
                m[s1[i]]++;
        }
        for (int i=0; i<n; i++) {
            if (m.find(s2[i])!=m.end()) {
                m[s2[i]]--;
                if (m[s2[i]]<0) {
                    return false;
                }
            }
            else
                return false;
        }
        return true;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    clock_t start=clock();
    clock_t end=clock();
    cout<<end-start<<endl;
    end=clock();
    cout<<end-start<<endl;
    return 0;
}

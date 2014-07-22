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
#include<unordered_set>
#include<unordered_map>
#include<ext/hash_map>
#include<time.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 500
#define MAX_N 105
#define MAX_M 20;
typedef long long ll;
using namespace std;



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (end==start) {
            return 2;
        }
        int n=start.length();
        queue<string> q;
        unordered_map<string, int> depth;
        q.push(start);
        depth[start]=1;
        while (!q.empty()) {
            string& a=q.front();
            for (int i=0; i<n; i++) {
                for (int j=0; j<26; j++) {
                    string tmp=a;
                    tmp[i]='a'+j;
                    if (tmp==end) {
                        return depth[a]+1;
                    }
                    if (tmp!=a&&dict.count(tmp)>0&&depth.count(tmp)==0) {
                        q.push(tmp);
                        depth[tmp]=depth[a]+1;
                    }
                }
            }
            q.pop();
        }
        return 0;
    }
};


int main() {
    Solution S;
    clock_t start=clock();
    clock_t end=clock();
    cout<<end-start<<endl;
    return 0;
}

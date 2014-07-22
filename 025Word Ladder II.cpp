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
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> res;
        if (end==start) {
            vector<string> path;
            path.push_back(start);
            path.push_back(end);
            res.push_back(path);
            return res;
        }
        int n=start.length();
        queue<string> q;
        unordered_map<string, int> depth;
        unordered_map<string, vector<string>> pre;
        q.push(start);
        depth[start]=1;
        int d=0;
        while (!q.empty()&&!d) {
            string& a=q.front();
            for (int i=0; i<n&&!d; i++) {
                for (int j=0; j<26&&!d; j++) {
                    string tmp=a;
                    tmp[i]='a'+j;
                    if (tmp==end) {
                        d = depth[a];
                        break;
                    }
                    //tmp要么没访问到，要么是同一深度
                    if (tmp!=a&&dict.count(tmp)>0&&(depth.count(tmp)==0||depth[tmp]==depth[a]+1)) {
                        if (depth.count(tmp)==0) {
                            q.push(tmp);
                            depth[tmp]=depth[a]+1;
                        }
                        pre[tmp].push_back(a);
                    }
                }
            }
            if (d==0) {
                q.pop();
            }
        }
        if (d==0) {
            return res;
        }
        while (!q.empty()&&depth[q.front()]==d) {
            string a=q.front();
            for (int i=0; i<n; i++) {
                for (int j=0; j<26; j++) {
                    string tmp=a;
                    tmp[i]=j+'a';
                    if (tmp==end) {
                        vector<string> path;
                        path.push_back(end);
                        findPath(start, a, path, pre, res);
                    }
                }
            }
            q.pop();
        }
        return res;
    }
private:
    void findPath(string start,string now,vector<string>& path,unordered_map<string, vector<string>> &pre,vector<vector<string>> &res){
        path.push_back(now);
        if (now==start) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        vector<string>& pres=pre[now];
        for (int i=0; i<pres.size(); i++) {
            findPath(start, pres[i], path, pre, res);
        }
        path.pop_back();
    }
};


int main() {
    Solution S;
    clock_t start=clock();
    unordered_set<string> dict={"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> res=S.findLadders("red","tax",dict);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    clock_t end=clock();
    cout<<end-start<<endl;
    return 0;
}

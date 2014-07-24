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
//#include<ext/hash_map>
//#include<time.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 100005
#define MAX_N 100005
#define MAX_M 105;
typedef long long ll;
using namespace std;
int const MOD=1000000007;
struct TreeLinkNode {
      int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
     };
class Solution {
public:
    int numDistinct(string S, string T) {
        int m=T.length();
        int n=S.length();
        if (m>n) {
            return 0;
        }
        vector<vector<int>> path(m+1,vector<int>(n+1,0));
        fill(path[0].begin(), path[0].end(), 1);
        for (int j=1; j<=n; j++) {
            for (int i=1; i<=m; i++) {
                path[i][j]=path[i][j-1]+(T[i-1]==S[j-1]?path[i-1][j-1]:0);
            }
        }
        return path[m][n];
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    return 0;
}

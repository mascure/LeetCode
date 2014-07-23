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
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode * start = root;
        TreeLinkNode * end = root;
        TreeLinkNode * levelEnd = root;
        while (start != NULL)
        {
            if (start->left != NULL)
            {
                end->next = start->left;
                end = end->next;
            }
            if (start->right != NULL)
            {
                end->next = start->right;
                end = end->next;
            }
            if (start == levelEnd)
            {
                start = start->next;
                levelEnd->next = NULL;
                levelEnd = end;
            }
            else
            {
                start = start->next;
            }
        }
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    return 0;
}

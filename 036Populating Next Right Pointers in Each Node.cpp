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
        con(root,NULL);
    }
private:
    void con(TreeLinkNode* node1,TreeLinkNode* node2){
        if (node1!=NULL) {
            node1->next=node2;
            con(node1->left,node1->right);
            if (node1->right!=NULL&&node2!=NULL&&node2->left!=NULL) {
                con(node1->right, node2->left);
            }
        }
        if (node2!=NULL) {
            con(node2->left, node2->right);
        }
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    return 0;
}

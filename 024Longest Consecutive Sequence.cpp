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
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> left,right;
        int res=0;
        for (int i=0; i<num.size(); i++) {
            int len1=left[num[i]-1],len2=right[num[i]+1];
            int len=len1+1+len2;
            left[num[i]]=max(left[num[i]],len1+1);
            right[num[i]]=max(right[num[i]],len2+1);
            right[num[i]-len1]=max(right[num[i]-len1],len);
            left[num[i]+len2]=max(left[num[i]+len2],len);
            cout<<num[i]<<" "<<left[num[i]]<<" "<<right[num[i]]<<" "<<endl;
            cout<<" "<<num[i]-len1<<":"<<right[num[i]-len1]<<" "<<num[i]+len2<<" "<<left[num[i]+len2]<<endl;
            res=max(res,len);
        }
        return res;
    }
};


int main() {
    Solution S;
    clock_t start=clock();
    clock_t end=clock();
    vector<int> num={-1,9,-3,-6,7,-8,-6,2,9,2,3,-2,4,-1,0,6,1,-9,6,8,6,5,2};
    cout<<S.longestConsecutive(num)<<endl;
    cout<<end-start<<endl;
    return 0;
}

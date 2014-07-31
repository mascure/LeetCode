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
    bool search(int A[], int n, int target) {
        int L=0,H=n-1;
        if(A[L]>=A[H]){
			if (A[L]==target||A[H]==target) {
                return true;
            }
            if (L!=H&&A[L]==A[H]) {
                while (L+1<n&&A[L]==A[L+1]) {
                    L++;
                }
                L++;
                while (H-1>=0&&A[H-1]==A[H]) {
                    H--;
                }
                H--;
            }
            if (L>H) {
                return false;
            }
            while (L<=H) {
                int mid=L+((H-L)>>1);
                if (A[mid]>=A[0]) {
                    L=mid+1;
                }
                else
                    H=mid-1;
            }
            if (A[0]<target) {
                L=0;
            }
            else{
                L=H+1,H=n-1;
            }
        }
        while (L<=H) {
            int mid=L+((H-L)>>1);
            if (A[mid]<target) {
                L=mid+1;
            }
            else if(A[mid]>target){
                H=mid-1;
            }
            else
                return true;
        }
        return false;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    Solution S;
    int A[]={1,3,5};
    clock_t start=clock();
    cout<<S.search(A, 3, 3)<<endl;
    clock_t end=clock();
    cout<<end-start<<endl;
    end=clock();
    cout<<end-start<<endl;
    return 0;
}

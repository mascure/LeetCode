#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<math.h>
#include<unordered_map>
#include<windows.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 10005
#define MAX_SIZE 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;
int const MAX_N=105;
struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
    bool canJump(int A[], int n) {
        int M=0;
		for(int i=0;i<n;i++){
			if(M>=i){
				M=max(M,i+A[i]);
			}
		}
		return M>=n-1;
    }
};
int main(){
	Solution S;
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
	}
	return 0;
}
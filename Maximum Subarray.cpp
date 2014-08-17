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
#define MAX_SIZE 1005
#define MAX_M 1005
#define MAX_T 105
#define MAX_P 55
#define MAX_Q 55
#define MAX_K 105

typedef unsigned long long ull;
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int now=A[0],M=A[0];
		for(int i=1;i<n;i++){
			if(now<=0)now=A[i];
			else now+=A[i];
			M=max(M,now);
		}
		return M;
    }
};
int main(){
	return 0;
}
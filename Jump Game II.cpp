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
    int jump(int A[], int n) {
		int last=0,step=0,cur=0;
		int res=0;
		for(int i=0;i<n;i++){
			if(i>last){
				last=cur;
				res++;
			}
			cur=max(cur,i+A[i]);
		}
		return res;
    }
};
int main(){
	return 0;
}
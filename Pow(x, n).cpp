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
	double pow(double x, int n) {
		if(n==0)return 1;
		if(x==0)return 0;
		if(n<0){
			x=1/x;
			n=-n;
		}
        double res=pow(x*x,n>>1);
		if(n&1)res*=x;
		return res;
    }
};
int main(){
	Solution S;
	return 0;
}
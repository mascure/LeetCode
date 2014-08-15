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
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=strlen(s);
		int t=len-1;
		while(t>=0&&s[t]==' ')t--;
		if(t<0)return 0;
		int start=t-1;
		while(start>=0&&isChar(s[start])){
			start--;
		}
		return t-start;
    }
private:
	bool isChar(char c){
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))return true;
		else return false;
	}
};
int main(){
	Solution S;
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
	}
	return 0;
}
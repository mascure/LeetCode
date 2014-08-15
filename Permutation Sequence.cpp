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
    string getPermutation(int n, int k) {
        vector<int> jie(n+1);
		jie[0]=1;
		for(int i=1;i<=n;i++){
			jie[i]=jie[i-1]*i;
		}
		if(k>jie[n])return "";
		vector<int> a(n);
		for(int i=0;i<n;i++)a[i]=i+1;
		int t=0;
		while(t<n-1){
			int tmp=(k-1)/(jie[n-t-1]);
			swap(a[t],a[t+tmp]);
			sort(a.begin()+(t+1),a.end());
			k-=(tmp*jie[n-t-1]);
			t++;
		}
		string res="";
		for(int i=0;i<n;i++){
			res+=('0'+a[i]);
		}
		return res;
    }
};
int main(){
	Solution S;
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		cout<<S.getPermutation(n,k)<<endl;
	}
	return 0;
}
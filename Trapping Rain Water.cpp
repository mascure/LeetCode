#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
const int MAX_N=2005;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
class Solution {
public:
    int trap(int A[], int n) {
		vector<int> maxLeft(n,0);
		vector<int> maxRight(n,0);
		for(int i=1;i<n;i++){
			maxLeft[i]=max(maxLeft[i-1],A[i-1]);
			maxRight[n-1-i]=max(maxRight[n-i],A[n-i]);
		}
		int res=0;
		for(int i=1;i<n;i++){
			int H=min(maxLeft[i],maxRight[i]);
			if(H>A[i])res+=H-A[i];
		}
		return res;
    }
};
int A[]={9,6,8,8,5,6,3};
int main(){
	Solution S;
	cout<<S.trap(A,7)<<endl;
	return 0;
}
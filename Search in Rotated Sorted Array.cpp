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
//#include <unordered_set>
using namespace std;
const int MAX_N=1000005;
const int inf=1000000;
const int MOD=1000000007;
const int MAX_WH=200;
typedef long long ll;

class Solution {
public:
    int search(int A[], int n, int target) {
		if(A[0]<=A[n-1]){
			int p=lower_bound(A,A+n,target)-A;
			if(A[p]==target)return p;
			else return -1;
		}
		else{
			int L=0,R=n;
			while(R>L){
				int mid=(L+R)/2;
				if(A[mid]>=A[0])L=mid+1;
				else R=mid;
			}
			if(target>=A[0]){
				int p=lower_bound(A,A+L,target)-A;
				if(A[p]==target)return p;
				else return -1;
			}
			else{
				int p=lower_bound(A+L,A+n,target)-A;
				if(A[p]==target)return p;
				else return -1;
			}
		}
    }
};

int main(){
	int A[2]={3,1};
	Solution S;
	cout<<S.search(A,2,1)<<endl;
	return 0;
}
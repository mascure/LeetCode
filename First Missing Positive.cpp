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
    int firstMissingPositive(int A[], int n) {
        buckSort(A,n);
		for(int i=0;i<n;i++)
			if(A[i]!=i+1)
				return i+1;
		return n+1;
    }
private:
	void buckSort(int A[],int n){
		for(int i=0;i<n;i++){
			while(A[i]!=i+1){
				//超出范围或者目标位置已是正确的数字
				if(A[i]<=0||A[i]>n||A[i]==A[A[i]-1])
					break;
				swap(A[i],A[A[i]-1]);
			}
		}
	}
};
int A[]={9,6,8,8,5,6,3};
int main(){
	Solution S;
	return 0;
}
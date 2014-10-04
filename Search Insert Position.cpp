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
    int searchInsert(int A[], int n, int target) {
        return lower_bound(A,A+n,target)-A;
    }
};

int main(){
	return 0;
}
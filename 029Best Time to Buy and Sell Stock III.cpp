#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<list>
#include <stack>
#include<queue>
#include<sstream>
#include<map>
//#include<unordered_set>
//#include<unordered_map>
//#include<ext/hash_map>
//#include<time.h>
#define inf 0x7fffffff
#define MAX_E 1000000
#define MAX_V 100005
#define MAX_N 100005
#define MAX_M 105;
typedef long long ll;
using namespace std;
int const MOD=1000000007;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res=0,n=prices.size();
        if(n<2)return 0;
        vector<int> rm(n,0);
        int rmax=n-1;
        for (int i=n-2; i>=0; i--) {
            if (prices[i]>prices[rmax]) {
                rmax=i;
            }
            rm[i]=max(rm[i+1],prices[rmax]-prices[i]);
        }
        res=max(res, rm[0]);
        int lleast=0;
        for (int i=0; i<n-1; i++) {
            if (prices[i]<prices[lleast]) {
                lleast=i;
            }
            res=max(res, prices[i]-prices[lleast]+rm[i+1]);
        }
        return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    cout<<S.maxProfit(p)<<endl;
    return 0;
}

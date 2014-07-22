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
        int res=0,leastI=0;
        int i=0,n=prices.size();
        while(i<n){
            while(i+1<n&&prices[i]>=prices[i+1])i++;
            leastI=i;
            while(i+1<n&&prices[i]<=prices[i+1])i++;
            res+=prices[i]-prices[leastI];
            i++;
        }
        return res;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    return 0;
}

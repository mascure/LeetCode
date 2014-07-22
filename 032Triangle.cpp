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
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
        vector<int> r1(n,0),r2(n,0);
        r1[0]=triangle[0][0];
        for (int i=1; i<n; i++) {
            for (int j=0; j<=i; j++) {
                int tmp=1000000000;
                if (j>0) {
                    tmp=min(tmp, r1[j-1]);
                }
                if (j!=i) {
                    tmp=min(tmp, r1[j]);
                }
                r2[j]=tmp+triangle[i][j];
            }
            copy(r2.begin(), r2.end(), r1.begin());
        }
        int res=1000000000;
        for (int i=0; i<n; i++) {
            res=min(res, r1[i]);
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

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
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex<0) {
            return res;
        }
        vector<int> last,now(1,1);
        for (int i=1; i<=rowIndex; i++) {
            last=now;
            now.resize(i+1, 1);
            for (int j=1; j<i; j++) {
                now[j]=last[j-1]+last[j];
            }
        }
        return res=now;
    }
};

int main() {
    //freopen("/Users/mascure/Desktop/main.in", "r", stdin);
    vector<int> p={3,2,6,5,0,3};
    Solution S;
    return 0;
}
